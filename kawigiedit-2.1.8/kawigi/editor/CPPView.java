package kawigi.editor;
import javax.swing.text.*;
import java.awt.*;
import java.util.*;

/**
 *	C++ Implementation of a View that takes care of syntax hilighting when
 *	rendering text.
 **/
public class CPPView extends GenericView
{
	/**
	 *	A map from token to its color.
	 **/
	protected static Hashtable<String,Color> colorHash;

	static
	{
		initColors();
	}

	/**
	 *	Initializes the keywords/tokens and their colors.
	 *
	 *	What this basically does is calls GenericView.getColors and
	 *	GenericView.readKeywords.  It is called when the class is loaded and
	 *	any time when the color settings might have changed.
	 **/
	public static void initColors()
	{
		colorHash = new Hashtable<String,Color>();
		getColors();
		readKeywords("cpp", true, colorHash);
	}

	/**
	 *	Creates a new C++ View to render this Element.
	 **/
	public CPPView(Element e)
	{
		super(e);
	}

	/**
	 *	Overridden from PlainView - this method gets called to render every
	 *	element of unselected text.
	 **/
	protected int drawUnselectedText(Graphics g, int x, int y, int p0, int p1) throws BadLocationException
	{
		String s = getDocument().getText(p0, p1 - p0);
		String before = getDocument().getText(0, p0);
		boolean inComment = false;
		for (int i=0; i<before.length(); i++)
		{
			if (inComment && before.charAt(i) == '/' && i > 0 && before.charAt(i-1) == '*')
				inComment = false;
			else if (!inComment && before.charAt(i) == '*' && i > 0 && before.charAt(i-1) == '/')
				inComment = true;
			else if (!inComment && before.charAt(i) == '\"')
				for (i = i+1; i<before.length() && before.charAt(i) != '\"' && before.charAt(i) != '\r' && before.charAt(i) != '\n'; i++)
					;
			else if (!inComment && before.charAt(i) == '\'')
				for (i = i+1; i<before.length() && before.charAt(i) != '\'' && before.charAt(i) != '\r' && before.charAt(i) != '\n'; i++)
					;
			else if (!inComment && before.charAt(i) == '/' && i > 0 && before.charAt(i-1) == '/')
				for (i = i+1; i<before.length() && before.charAt(i) != '\r' && before.charAt(i) != '\n'; i++)
					;
		}
		return drawTabbedText(s, x, y, g, p0, false, inComment);
	}

	/**
	 *	Overridden from PlainView - this method gets called to render every
	 *	element of selected text, so that I could change how it's displayed if I
	 *	want.
	 **/
	protected int drawSelectedText(Graphics g, int x, int y, int p0, int p1) throws BadLocationException
	{
		String s = getDocument().getText(p0, p1 - p0);
		String before = getDocument().getText(0, p0);
		boolean inComment = false;
		for (int i=0; i<before.length(); i++)
		{
			if (inComment && before.charAt(i) == '/' && i > 0 && before.charAt(i-1) == '*')
				inComment = false;
			else if (!inComment && before.charAt(i) == '*' && i > 0 && before.charAt(i-1) == '/')
				inComment = true;
			else if (!inComment && before.charAt(i) == '\"')
				for (i = i+1; i<before.length() && before.charAt(i) != '\"' && before.charAt(i) != '\r' && before.charAt(i) != '\n'; i++)
					;
			else if (!inComment && before.charAt(i) == '\'')
				for (i = i+1; i<before.length() && before.charAt(i) != '\'' && before.charAt(i) != '\r' && before.charAt(i) != '\n'; i++)
					;
			else if (!inComment && before.charAt(i) == '/' && i > 0 && before.charAt(i) == '/')
				for (i = i+1; i<before.length() && before.charAt(i) != '\r' && before.charAt(i) != '\n'; i++)
					;
		}
		return drawTabbedText(s, x, y, g, p0, true, inComment);
	}

	/**
	 *	Renders the text segment onto the given Grapnics context.
	 *
	 *	Originally, this looked a lot like drawTabbedText in the
	 *	javax.swing.text.Utilities class with a little bit of tokenizing, but
	 *	now it's pretty much modified to my own style.  Unfortunately, at some
	 *	point in time, my indentation got all weird (probably as a result of me
	 *	using tabs and the original implementation mixing spaces and tabs), so
	 *	there may be some weird-looking parts left in the code.
	 *
	 *	It's possible that I'll eventually change this to work differently with
	 *	compiler directives.
	 *
	 *	This is the magic of my syntax hilighting in C++.
	 **/
	protected int drawTabbedText(String s, int x, int y, Graphics g, int startOffset, boolean selected, boolean inComment)
	{
		if (selected)
			g.setColor(((JTextComponent)getContainer()).getSelectedTextColor());
		FontMetrics metrics = g.getFontMetrics();
		int flushIndex = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s.charAt(i) == '/' && i < s.length()-1 && s.charAt(i+1) == '*')
			{
				if (!selected)
					if (inComment)
						g.setColor(commentColor);
					else
		    			g.setColor(getColor(s.substring(flushIndex, i)));
	    		g.drawString(s.substring(flushIndex, i), x, y);
				x += metrics.stringWidth(s.substring(flushIndex, i));
	   	 		flushIndex = i;
				inComment = true;
			}
			//strings:
			if (!inComment && s.charAt(i) == '\"')
			{
	    		if (flushIndex < i)
	    		{
					if (!selected)
						if (inComment)
							g.setColor(commentColor);
						else
			    			g.setColor(getColor(s.substring(flushIndex, i)));
		    		g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
		   	 		flushIndex = i;
		    	}
				i++;
				for (; i<s.length() && s.charAt(i) != '\"' && s.charAt(i) != '\n' && s.charAt(i) != '\r'; i++)
				{
					if (s.charAt(i) == '\t')
					{
						if (i > flushIndex)
						{
							if (!selected)
		    					g.setColor(stringColor);
							g.drawString(s.substring(flushIndex, i), x, y);
						}
						flushIndex = i + 1;
						x = (int)nextTabStop((float)x, startOffset+i);
					}
					if (s.charAt(i) == '\\')
						i++;
				}
				if (!selected)
					if (inComment)
						g.setColor(commentColor);
					else
			    		g.setColor(stringColor);
				g.drawString(s.substring(flushIndex, i), x, y);
				x += metrics.stringWidth(s.substring(flushIndex, i));
				if (i < s.length() && s.charAt(i) == '\"')
				{
					g.drawString(s.substring(i, i+1), x, y);
			   		x += metrics.charWidth(s.charAt(i));
			    }
	    		flushIndex = i+1;
			}
			//Treating characters like strings:
			else if (!inComment && s.charAt(i) == '\'')
			{
	    		if (flushIndex < i)
	    		{
					if (!selected)
						if (inComment)
							g.setColor(commentColor);
						else
			   				g.setColor(getColor(s.substring(flushIndex, i)));
		   	 		g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
		    		flushIndex = i;
		    	}
				i++;
				for (; i<s.length() && s.charAt(i) != '\'' && s.charAt(i) != '\n' && s.charAt(i) != '\r'; i++)
				{
					if (s.charAt(i) == '\t')
					{
						if (i > flushIndex)
						{
							if (!selected)
		    						g.setColor(stringColor);
							g.drawString(s.substring(flushIndex, i), x, y);
							x += metrics.stringWidth(s.substring(flushIndex, i));
						}
						flushIndex = i + 1;
					}
					if (s.charAt(i) == '\\')
						i++;
				}
				if (!selected)
					if (inComment)
						g.setColor(commentColor);
					else
			    		g.setColor(stringColor);
				g.drawString(s.substring(flushIndex, i), x, y);
				x += metrics.stringWidth(s.substring(flushIndex, i));
				if (i < s.length() && s.charAt(i) == '\'')
				{
					g.drawString(s.substring(i, i+1), x, y);
			    	x += metrics.charWidth(s.charAt(i));
			   	}
		    	flushIndex = i+1;
			}
			//Single-line comments
			else if (!inComment && s.charAt(i) == '/' && i < s.length()-1 && s.charAt(i+1) == '/')
			{
				if (flushIndex < i)
	    		{
					if (!selected)
						if (inComment)
							g.setColor(commentColor);
						else
				    		g.setColor(getColor(s.substring(flushIndex, i)));
				    g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
			    	flushIndex = i;
		    	}
				for (; i<s.length() && s.charAt(i) != '\n' && s.charAt(i) != '\r'; i++)
				{
					if (s.charAt(i) == '\t')
					{
						if (i > flushIndex)
						{
							if (!selected)
		    					g.setColor(commentColor);
							g.drawString(s.substring(flushIndex, i), x, y);
							x += metrics.stringWidth(s.substring(flushIndex, i));
						}
						flushIndex = i + 1;
						x = (int)nextTabStop((float)x, startOffset+i);
					}
				}
				if (!selected)
					g.setColor(commentColor);
				//Me looking cool on everyone else's code, and also mimicking the TopCoder logo.
				if (s.substring(flushIndex, i).endsWith("[KawigiEdit]"))
			   	{
			   		if (!s.substring(flushIndex, i).equals("[KawigiEdit]"))
			   		{
			   			if (!selected)
			   				g.setColor(commentColor);
			   			g.drawString(s.substring(flushIndex, s.indexOf("[KawigiEdit]", flushIndex)), x, y);
			   			x += metrics.stringWidth(s.substring(flushIndex, s.indexOf("[KawigiEdit]", flushIndex)));
			   		}
			   		Font oldFont = g.getFont();
			   		g.setFont(oldFont.deriveFont(Font.BOLD));
			    	if (!selected)
				   		g.setColor(getContainer().getForeground());
			    	g.drawString("[KawigiEdit]", x, y);
			    	if (!selected)
				   		g.setColor(Color.red);
		    		g.drawString("Edit", x+g.getFontMetrics().stringWidth("[Kawigi"), y);
					x += g.getFontMetrics().stringWidth(s.substring(flushIndex, i));
			   		g.setFont(oldFont);
			   	}
			   	else
				{
					g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
				}
	    		flushIndex = i+1;
			}
			//Tabs to expand:
			else if (s.charAt(i) == '\t')
			{
				if (i > flushIndex)
				{
					if (!selected)
			    		g.setColor(getColor(s.substring(flushIndex, i)));
					g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
				}
				flushIndex = i + 1;
				x = (int) nextTabStop((float) x, startOffset+i);
			}
			//end of line case:
			else if ((s.charAt(i) == '\n') || (s.charAt(i) == '\r'))
			{
				if (i > flushIndex)
				{
					if (!selected)
						if (inComment)
							g.setColor(commentColor);
						else
			 			g.setColor(getColor(s.substring(flushIndex, i)));
					g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
				}
				flushIndex = i + 1;
	    	}
	    	//parsing compiler directives:
	    	else if (!inComment && s.charAt(i) == '#')
	    	{
	    		if (flushIndex < i)
	    		{
					if (!selected)
			    		g.setColor(getColor(s.substring(flushIndex, i)));
		    		g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
		   	 		flushIndex = i;
		    	}
				i++;
				for (; i<s.length() && s.charAt(i) != '\n' && s.charAt(i) != '\r' && (s.charAt(i) != '/' || i+1 >= s.length() || (s.charAt(i+1) != '/' && s.charAt(i+1) != '*')); i++)
				{
					if (s.charAt(i) == '\t')
					{
						if (i > flushIndex)
						{
							if (!selected)
		    					g.setColor(directiveColor);
							g.drawString(s.substring(flushIndex, i), x, y);
							x += metrics.stringWidth(s.substring(flushIndex, i));
						}
						flushIndex = i + 1;
						x = (int)nextTabStop((float)x, startOffset+i);
					}
				}
				i--;
				if (i >= flushIndex)
				{
					if (!selected)
				    	g.setColor(getColor(s.substring(flushIndex, i+1).split("[ \\t\\n\\r\\f]")[0]));
					g.drawString(s.substring(flushIndex, i+1), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i+1));
				}
				flushIndex = i+1;
	    	}
			//KawigiEdit control stuff:
			else if (i < s.length()-4 && s.charAt(i) == '<' && s.charAt(i+1) == '%' && s.charAt(i+2) == ':' && s.indexOf('%', i+2) >= 0 && s.indexOf('%', i+2) < s.length()-1 && s.charAt(s.indexOf('%', i+2)+1) == '>')
			{
				if (flushIndex < i)
				{
					if (!selected)
						if (inComment)
							g.setColor(commentColor);
						else
							g.setColor(getColor(s.substring(flushIndex, i)));
					g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
				}
				flushIndex = i;
				i = s.indexOf('%', i+2)+1;
				g.setColor(tagColor);
				g.drawString(s.substring(flushIndex, i+1), x, y);
				x += metrics.stringWidth(s.substring(flushIndex, i+1));
				flushIndex = i+1;
			}
	    	//valid token characters:
			else if (Character.isLetterOrDigit(s.charAt(i)) || s.charAt(i) == '_')
			{
			}
		    else
		    {
		    	//flush the token if there is a previous token:
		    	if (flushIndex < i)
		    	{
					if (!selected)
						if (inComment)
							g.setColor(commentColor);
						else
			    			g.setColor(getColor(s.substring(flushIndex, i)));
			    	g.drawString(s.substring(flushIndex, i), x, y);
					x += metrics.stringWidth(s.substring(flushIndex, i));
		    	}
		    	//draw the current character:
				if (!selected)
					if (inComment)
						g.setColor(commentColor);
					else
		    			g.setColor(getColor(s.substring(i, i+1)));
				g.drawString(s.substring(i, i+1), x, y);
				flushIndex = i+1;
				x += metrics.charWidth(s.charAt(i));
			}
			//end of comment
			if (i < s.length() && s.charAt(i) == '/' && i > 0 && s.charAt(i-1) == '*')
				inComment = false;
		}
		//flush the rest out, if there is anything.
		if (flushIndex < s.length())
		{
			if (!selected)
				if (inComment)
					g.setColor(commentColor);
				else
					g.setColor(getColor(s.substring(flushIndex, s.length())));
			g.drawString(s.substring(flushIndex, s.length()), x, y);
			x += metrics.stringWidth(s.substring(flushIndex, s.length()));
		}
		return x;
	}

	/**
	 *	Returns the color to use on the given token.
	 *
	 *	This will return the default foreground color, if no special color is
	 *	assigned to that token.
	 **/
	protected Color getColor(String word)
	{
		if (colorHash.containsKey(word))
			return (Color)colorHash.get(word);
		else
			return getContainer().getForeground();
	}

	/**
	 *	Extension of the generic getIntervals() method that includes compiler
	 *	directive matches.
	 **/
	public ArrayList<Interval> getIntervals()
	{
		ArrayList<Interval> ret = super.getIntervals();
		try
		{
			parseIndex = 0;
			lineIndex = 1;
			findIntervals(ret, getDocument().getText(0, getDocument().getLength()), new String[]{"#if", "#endif"}, true);
			parseIndex = 0;
			lineIndex = 1;
			findIntervals(ret, getDocument().getText(0, getDocument().getLength()), new String[]{"#ifdef", "#endif"}, true);
			parseIndex = 0;
			lineIndex = 1;
			findIntervals(ret, getDocument().getText(0, getDocument().getLength()), new String[]{"#ifndef", "#endif"}, true);
		}
		catch (BadLocationException ex)
		{
		}
		return ret;
	}
}
