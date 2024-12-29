const prompt = require('prompt-sync')({sigint: true});

let a = prompt('Enter a: ');
let b = prompt('Enter b: ');

let result = "";
let left = Math.floor(a / b);
result += left;
result += ".";

a %= b;

let k = 1;
let frac = [];
let rems = [a];
let rep = -1;
while (true) {
  // next digit of a/b
  // (10^p)a > b
  let p = 0;
  let p10 = 1;
  while ((p10*a) < b) {
    p++;
    p10 *= 10;
  }  
  let q = Math.floor((p10*a) / b);
  let r = ((p10*a) % b);
  // a/b = q*(1/p10)+(r/b)*(1/p10)  -> problem a/b repeats as r/b, shifted by p places
  let zero = "0";
  frac.push(zero.repeat(p-1) + q);
  rems.push(r);
  rep = rems.indexOf(r);
  if (r == 0 || (rep != -1 && rep !== rems.length - 1)) {
    console.log(frac, rep, r, rems);
    break;
  }
  a = r;
}
for (let i = 0; i < frac.length; i++) {
  if (i == rep) {
    result += "*";
  }
  result += frac[i];
}
console.log(result);
