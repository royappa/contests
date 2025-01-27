vector<string> split_nonre(string s, string sep)  // sep is a list of possible sep characters, not a substring
{
  char* sC = new char[s.size() + 1];
  strcpy(sC, s.c_str());

	char *sepC = (char *) sep.c_str();

	char *word;
	vector<string> results;
	while ((word = strtok(sC, sepC)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

vector<string> split_subseq(string& s, string& sep) {
    vector<string> result;
    int start = 0;
    int sep_pos;

    if (sep.empty()) {
        result.push_back(s);
        return result;
    }
    // Find the separator in the string and split
    while ((sep_pos = s.find(sep, start)) != string::npos) {
        result.push_back(s.substr(start, sep_pos - start));
        start = sep_pos + sep.size(); // Move past the separator
    }

    // Add the last segment (or the entire string if no separator was found)
    result.push_back(s.substr(start));
    return result;
}