/**
* File Name: Assign12.cpp
*
* Academic Integrity Statement:
* I certify that, while others may have assisted me in brainstorming, debugging, and validating this program,
* the program itself is my own work. I understand that submitting code that is the work of other individuals
* is a violation of the course Academic Integrity Policy and may result in zero credit for the assignment, or
* course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my
* original work to another individual could also result in zero credit for the assignment, or course failure
* and a report to the Academic Dishonesty Board. See Academic Integrity for Students
Links to an external site.
*
* Assisted by and Assisted line numbers:Assisted by "https://stackoverflow.com/questions/13779321/accept-only-letters"
* Assisted line ( 55). Assisted by "https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case"
* Assisted line ( 59 ). Assisted by Prof. Meng Su lecture video and "https://cplusplus.com/forum/general/102469/" about correct
* ways to insert things into a tree,Assisted Line (66 ).
* Your Name: YUERAN MA
* Your PSU user ID:  ymm5252
* Course title: CMPSC122 Semester 2024
* Description: This is a coding project involves Tree data structure and file handling techniques.
**/
#include <iostream>//standard
#include <fstream>//we used file
#include <string>
using namespace std;

struct WordCount {

string word;
int count;
WordCount(const string& wd, int ct) {//constructor, because we need to initialize values

word = wd;
count = ct;
}

WordCount() {//default constructor, also because of initialization
word = "a";
count = 1;
}
};

struct TreeNode {
WordCount info;
TreeNode* left;
TreeNode* right;

TreeNode(const string& word) {
info = WordCount(word, 1);
left = nullptr;
right = nullptr;//initialize
}
};

bool filter(char character) {//because we only want letters
return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9');//from satckoverflow.com
}

char noCapital(char character) {
if (character >= 'A' && character <= 'Z') {//decapitalize the capital letters
return character + ('a' - 'A');
}
return character;
}

void insertion(TreeNode*& root,const string& word) {
if (root == nullptr) {
root = new TreeNode(word) ;

}
else if (word < root->info.word) {
insertion(root->left, word);
}
else if (word > root->info.word) {
insertion(root->right, word);
}
else {
root->info.count++;
}
}




void printTree(TreeNode* root, ofstream& revisedFile) {
if (root != nullptr) {
printTree(root->left, revisedFile);
revisedFile << root->info.word << ": " << root->info.count << endl;
printTree(root->right, revisedFile);
}

}

int main()
{

string origfileName;
string revisedfileName;
cout << "Please input the name of your original file" << endl;
cin >> origfileName;
cout << "Please input the name of the file that you would like to contain results" << endl;
cin >> revisedfileName;


ifstream origFile(origfileName);
ofstream revisedFile(revisedfileName);

if (!origFile) {
cout << "Error" << endl;
return 0;
}

TreeNode* root = nullptr;
string word;
while (origFile >> word) {
string revisedWord;
for (int i = 0; i < word.length(); i++) {//iterates through characters

char character = word[i];
if (filter(character)) {
revisedWord += noCapital(character);
}
}
if (revisedWord.length() >= 3) {
insertion(root, revisedWord);
}
}
printTree(root, revisedFile);

origFile.close();
revisedFile.close();

cout << "Task completed, please open your file to read" << endl;
return 0;
}
/*Sample outputs:
1863: 1
above: 1
add: 1
address: 1
advanced: 1
ago: 1
all: 1
altogether: 1
and: 6
any: 1
are: 3
battlefield: 1
before: 1
birth: 1
brave: 1
brought: 1
but: 2
can: 5
cause: 1
civil: 1
come: 1
conceived: 2
consecrate: 1
consecrated: 1
continent: 1
created: 1
dead: 3
dedicate: 2
dedicated: 4
detract: 1
devotion: 2
did: 1
died: 1
earth: 1
endure: 1
engaged: 1
equal: 1
far: 2
fathers: 1
field: 1
final: 1
fitting: 1
for: 5
forget: 1
forth: 1
fought: 1
four: 1
freedom: 1
from: 2
full: 1
gave: 2
gettysburg: 2
god: 1
government: 1
great: 3
ground: 1
hallow: 1
have: 5
here: 8
highly: 1
honored: 1
increased: 1
larger: 1
last: 1
liberty: 1
little: 1
live: 1
lives: 1
living: 2
long: 2
measure: 1
men: 2
met: 1
might: 1
nation: 5
never: 1
new: 2
nobly: 1
nor: 1
not: 5
note: 1
november: 1
now: 1
our: 2
pennsylvania: 1
people: 3
perish: 1
place: 1
poor: 1
portion: 1
power: 1
proper: 1
proposition: 1
rather: 2
remaining: 1
remember: 1
resolve: 1
resting: 1
say: 1
score: 1
sense: 1
seven: 1
shall: 3
should: 1
struggled: 1
take: 1
task: 1
testing: 1
that: 13
the: 12
their: 1
these: 2
they: 3
this: 4
those: 1
thus: 1
under: 1
unfinished: 1
vain: 1
war: 2
what: 2
whether: 1
which: 2
who: 3
will: 1
work: 1
world: 1
years: 1
*/