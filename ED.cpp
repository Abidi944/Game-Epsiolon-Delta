#include<iostream>
#include<cmath>
#include<iomanip>
#include<conio.h>
using namespace std;

struct match_history{
int score_p1;
int score_p2;
match_history* next;
};

struct game{
	string p1;
	string p2;
	match_history* head;
};game matches[100];
void play(int& n_game);
void display_home(int& n_game);

void insert_score(match_history*& head,int a,int b,int
indeks_game){
	match_history* match_baru=new match_history;
	match_baru->score_p1=a;
	match_baru->score_p2=b;
	match_baru->next=NULL;
	if(head==NULL){
		matches[indeks_game].head=match_baru;
	}
	else{
		match_history* current = head;
 	while (current->next != NULL) {
 		current = current->next;
 	}
 current->next = match_baru;
	}
}

void menampilkan_soal(int degree, int arr[],double epsilon,int 
limit){
	cout<<"Here is the Polynomial : \n"<<endl;
	cout<<"\t\t";
	if(degree==2){
		cout<<arr[0]<<"x^2 + ("<<arr[1]<<")x + 
("<<arr[2]<<")"<<endl;
	}
	else{
		cout<<arr[0]<<"x + ("<<arr[1]<<")"<<endl;
	}
	cout<<"The Limit is Evaluated When X Approaches 
"<<limit<<endl;
	cout<<"Your Task is to Find the Delta Given the Epsilon is 
"<<epsilon<<endl; 
}

bool mencocokkan (string& first, string& second) {
	if (first.size() < second.size()) {
	return false;
	}
	for (int i = 0; i <= first.size() - second.size(); ++i) {
		bool found = true;
		for (int j = 0; j < second.size(); ++j) {
			if (first[i + j] != second[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			return true;
		}}
	return false;}
	
void mencari_hasil_match(int n_game){
	system("cls");
	string name;
	cout<<" Find player name : ";
	cin>>name;
	bool found=1;
	for(int i=0;i<=n_game;i++){	
		
	if(mencocokkan(matches[i].p1,name)||mencocokkan(matches[i].p2
,name)){
found=0;
cout<<"\n";
cout<<" | MATCH RESULT 
|"<<endl;
 cout<<" |===============================|"<<endl;
cout<<" | 
"<<left<<setw(10)<<matches[i].p1<<" | 
"<<left<<setw(10)<<matches[i].p2<<" |"<<endl;
match_history* current=matches[i].head;
 while(true){
cout<<" | 
"<<right<<setw(3)<<current->score_p1<<" | 
"<<right<<setw(3)<<current->score_p2<<" |"<<endl;
 current=current->next;
 if(current==NULL)break;
}
cout<<" 
|===============================|"<<endl;
}
}
if(found){
cout<<"\t There is no such player name!"<<endl;
}
system("pause");
system("cls");
display_home(n_game);}

double find_answer(int degree,int arr[],double epsilon,int 
evaluate){
double hasil;
if(degree==2){
if(arr[1]*arr[1]-4*arr[0]*arr[2]==0){
hasil=sqrt(epsilon);
}
else{
double a=arr[0];
double b=arr[1];
double divide=b/a;
double hasil_pengurangan = abs(divide+2*evaluate);
hasil=epsilon/hasil_pengurangan;
}}
else{
double b=abs(arr[0]);
hasil=epsilon/b;
}
return hasil;}

bool check_answer(double delta,double jawaban){
bool hasil;
if(delta==jawaban){
hasil =true;
}
else{
hasil=false;
}
return hasil;}

void match_result(int n_game,int score_p1_part1,int 
score_p2_part1,int score_p1,int score_p2){
cout <<left << setw(45)<<matches[n_game].p1+" : The 
Challenger "<<"+("<<score_p1_part1<<")"<<endl;
cout <<left << setw(45)<<matches[n_game].p2+" : 
"<<"+"<<score_p2_part1<<endl;
cout <<left << setw(45)<<matches[n_game].p1+" : 
"<<"+"<<score_p1<<endl;
cout <<left << setw(45)<<matches[n_game].p2+" : The 
Challenger "<<"+("<<score_p2<<")"<<endl;}

void menampilkan_match_history(int n_game){
system("cls");
if(n_game==0){
cout<<"\t There is no game played yet!"<<endl;}
else{
cout<<"\n";
cout<<" | MATCH RESULT 
|"<<endl;
 cout<<" |===============================|"<<endl;
for(int i=0;i<n_game;i++){
cout<<" | 
"<<left<<setw(10)<<matches[i].p1<<" | 
"<<left<<setw(10)<<matches[i].p2<<" |"<<endl;
match_history* current=matches[i].head;
 while(true){
cout<<" | 
"<<right<<setw(3)<<current->score_p1<<" | 
"<<right<<setw(3)<<current->score_p2<<" |"<<endl;
 current=current->next;
 if(current==NULL)break;
}
cout<<" 
|===============================|"<<endl;
} }
system("pause");
system("cls");
display_home(n_game);}

void tutorial(int n_game){
system("cls");
cout<<"\t\t\t>>TUTORIAL<<"<<endl;
cout<<"|=====================================================
===========|"<<endl;
cout<<"|\t\t>>FORMAL DEFINITION OF LIMIT<< 
|"<<endl;
cout<<"| Let f(x) be a function defined on an open interval 
around x0. |"<<endl;
cout<<"| We say that the limit of f(x) as x approaches x0 is 
L, i.e |"<<endl;
cout<<"| 
|";
cout<<"\n|\t x→x0 lim f(x) = L, 
|"<<endl;
cout<<"| 
|";
cout<<"\n| if for every ε>0 (epsilon>0), 
|"<<endl;
cout<<"| There exists δ>0 (delta>0) such that for all x 
where |"<<endl;
cout<<"| 
|";
cout<<"\n|\t0 < | x - x0 | < δ ==> | f(x) – L | < ε. 
|"<<endl;
cout<<"| 
|";
cout<<"\n| For more detailed explanation about this 
defintion, |"<<endl;
cout<<"| You can check on this link 
https://youtu.be/kfF40MiS7zA |"<<endl;
cout<<"|=====================================================
===========|"<<endl;
cout<<"\n The main goal of this game is to introduce you to 
calculus, "<<endl;
cout<<" Especially to the formal definition of limit"<<endl;
cout<<" This is a dual-player game"<<endl;
cout<<" In each match, both player will play as a challenger 
alternately "<<endl;
cout<<" The challenger will set up the function including the 
epsilon"<<endl;
cout<<" In turn, the opponent will guess the delta given the 
epsilon with respect to the function"<<endl;
cout<<" REMEMBER, This game only provide up to 2 degree of 
polynomial function "<<endl;
cout<<" Therefore, there are only two function which is 
linear function and quadratic function"<<endl;
cout<<" You also need to know that if the challenger insert 
the incorrect delta given the epsilon,"<<endl;
cout<<" There will be a punishment in term of score,"<<endl; 
cout<<" The weight of punishment will be according to the 
weight of the question"<<endl;
cout<<" If the opponent guessed incorrectly and if the error 
is in between 1*10^-6,"<<endl;
cout<<" Then the opponent will gain half of the question 
weight"<<endl;
cout<<"\n Alright, guess you're good to go!"<<endl;
system("pause");
system("cls");
display_home(n_game);}

void display_home(int& n_game){
int pilih=1;
int a;
while(true){
if(pilih==1){
system("cls");
cout<<" Welcome to The Epsilon-Delta Game!\n";
cout<<"|==============================|"<<endl;
cout<<"| ===>>[ PLAY! ]<<==== |"<<endl;
cout<<"| [ MATCH HISTORY ] |"<<endl;
cout<<"| [ FIND MATCH ] |"<<endl;
cout<<"| [ TUTORIAL ] |"<<endl;
cout<<"| [ EXIT ] |"<<endl;
cout<<"|==============================|"<<endl;
}else if(pilih==2){
system("cls");
cout<<" Welcome to The Epsilon-Delta Game!\n";
cout<<"|==============================|"<<endl;
cout<<"| [ PLAY! ] |"<<endl;
cout<<"| ===>>[ MATCH HISTORY ]<<==== |"<<endl;
cout<<"| [ FIND MATCH ] |"<<endl;
cout<<"| [ TUTORIAL ] |"<<endl;
cout<<"| [ EXIT ] |"<<endl;
cout<<"|==============================|"<<endl;
}else if(pilih==3){
system("cls");
cout<<" Welcome to The Epsilon-Delta Game!\n";
cout<<"|==============================|"<<endl;
cout<<"| [ PLAY! ] |"<<endl;
cout<<"| [ MATCH HISTORY ] |"<<endl;
cout<<"| ===>>[ FIND MATCH ]<<==== |"<<endl;
cout<<"| [ TUTORIAL ] |"<<endl;
cout<<"| [ EXIT ] |"<<endl;
cout<<"|==============================|"<<endl;
}else if(pilih==4){
system("cls");
cout<<" Welcome to The Epsilon-Delta Game!\n";
cout<<"|==============================|"<<endl;
cout<<"| [ PLAY! ] |"<<endl;
cout<<"| [ MATCH HISTORY ] |"<<endl;
cout<<"| [ FIND MATCH ] |"<<endl;
cout<<"| ===>>[ TUTORIAL ]<<==== |"<<endl;
cout<<"| [ EXIT ] |"<<endl;
cout<<"|==============================|"<<endl;
}else if(pilih==5){
system("cls");
cout<<" Welcome to The Epsilon-Delta Game!\n";
cout<<"|==============================|"<<endl;
cout<<"| [ PLAY! ] |"<<endl;
cout<<"| [ MATCH HISTORY ] |"<<endl;
cout<<"| [ FIND MATCH ] |"<<endl;
cout<<"| [ TUTORIAL ] |"<<endl;
cout<<"| ===>>[ EXIT ]<<==== |"<<endl;
cout<<"|==============================|"<<endl;
}
a=getch();
if(a==72){
pilih--;
if(pilih<1){
pilih=5;
}
}else if(a==80){
pilih++;
if(pilih>5){
pilih=1;
}
}else if(a==13){
break;
}
}
if(pilih==1){
play(n_game);
}
else if(pilih==2){
menampilkan_match_history(n_game);
}
else if(pilih==3){
mencari_hasil_match(n_game);
}
else if(pilih==4){
tutorial(n_game);
}
else {
return;}}

void play(int& n_game){
system("cls");
cout<<"==>Please Insert the Challenger 1 Name : ";
cin>>matches[n_game].p1;
cout<<"==>Please Insert the Challenger 2 Name : ";
cin>>matches[n_game].p2;
system("cls");
while(true){
int degree,evaluate,weight,score_p1,score_p2;
int score_p1_part1,score_p2_part1;
double delta,epsilon,answer,real_answer;
char play_again;
while(true){
cout<<"Alright, Remember Not to Show the Screen 
While You're Setting Up the Challenge! \n";
cout<<"Hey "<<matches[n_game].p1<<"! Please 
Insert the Degree of Your Polynomial [1 or 2] : ";
cin>>degree;
if(degree==1||degree==2)break;
}
int arr[degree+1];
for(int i=0;i<degree+1;i++){
if(degree==1){
if(i==0){
cout<<"Please Insert the Coefficent : 
";
cin>>arr[i];
}
else{
cout<<"Please Insert the Constant : 
";
cin>>arr[i];
}
}
else{
if(i==2){
cout<<"Please Insert the Constant : 
";
cin>>arr[i];
}
else{
cout<<"Please Insert the Coefficient 
: ";
cin>>arr[i];
}
}
}
cout<<"The Limit is Evaluated When X Approaches : ";
cin>>evaluate;
cout<<"Set the Value of Your Epsilon : ";
cin>>epsilon;
cout<<"According to Your Epsilon,Insert your Delta : ";
cin>>delta;
while(true){
cout<<"How Many Points You Want to Give this 
Problem? The Weight Must be in Interval[1,20] : ";
cin>>weight;
if(weight>0&&weight<21)break;
}
system("cls");
cout<<"Now, Your Turn "<<matches[n_game].p2<<"!, Insert 
Your Delta According to the Given Polynomial ";
menampilkan_soal(degree,arr,epsilon,evaluate);
cin>>answer;
system("cls");
cout<<"Here is the result : \n";
if(check_answer(answer,find_answer(degree,arr,epsilon,evaluat
e))){
cout <<left << setw(45)<<matches[n_game].p2 + " 
Got the Correct Answer!" <<"+"<<weight<<endl;
score_p2_part1=weight;
}
else 
if(check_answer(answer,find_answer(degree,arr,epsilon,evaluate))==f
alse&& abs(answer-find_answer(degree,arr,epsilon,evaluate))<=1e06){
cout <<left << setw(45)<<matches[n_game].p2+" 
Nearly Got the Correct Answer!"<<"+"<<weight/2<<endl;
score_p2_part1=weight/2;
}
else{
cout <<left << setw(45)<<matches[n_game].p2+" Got 
the Wrong Answer!"<<"+0"<<endl;
score_p2_part1=0;
}
if(check_answer(delta,find_answer(degree,arr,epsilon,evaluate
))&&abs(answer-find_answer(degree,arr,epsilon,evaluate))>1e-06){
cout <<left << setw(45)<<matches[n_game].p1+" 
Insert the Correct Answer"<<"+"<<weight<<endl;
score_p1_part1=weight;
}
else 
if(check_answer(delta,find_answer(degree,arr,epsilon,evaluate))&&ab
s(answer-find_answer(degree,arr,epsilon,evaluate))<=1e-06){
cout <<left << setw(45)<<matches[n_game].p1+" 
Insert the Correct Answer"<<"+0"<<endl;
score_p1_part1=0;
}
else{
cout <<left << setw(45)<<matches[n_game].p1+" 
Insert the Wrong Answer!"<<"-"<<weight<<endl;
score_p1_part1=-weight;
}
insert_score(matches[n_game].head,score_p1_part1,score_p2_par
t1,n_game);
system("pause");
system("cls");
cout<<"Now, It's Your Turn, "<<matches[n_game].p2<<", 
Please Set Up Your Challenge! ";
while(true){
cout<<"Alright, Remember Not to Show the Screen 
While You're Setting Up the Challenge! \n";
cout<<"Hey "<<matches[n_game].p2<<"! Please 
Insert the Degree of Your Polynomial [1 or 2] : ";
cin>>degree;
if(degree==1||degree==2)break;
}
for(int i=0;i<degree+1;i++){
if(degree==1){
if(i==0){
cout<<"Please Insert the Coefficent : 
";
cin>>arr[i];
}
else{
cout<<"Please Insert the Constant : 
";
cin>>arr[i];
}
}
else{
if(i==2){
cout<<"Please Insert the Constant : 
";
cin>>arr[i];
}
else{
cout<<"Please Insert the Coefficient 
: ";
cin>>arr[i];
}
}
}
cout<<"The Limit is Evaluated When X Approaches : ";
cin>>evaluate;
cout<<"Set the Value of Your Epsilon : ";
cin>>epsilon;
cout<<"According to Your Epsilon,Insert your Delta : ";
cin>>delta;
while(true){
cout<<"How Many Points You Want to Give this 
Problem? The Weight Must be in Interval[1,20] : ";
cin>>weight;
if(weight>0&&weight<21)break;
}
system("cls");
cout<<"Now, Your Turn "<<matches[n_game].p2<<"!, Insert 
Your Delta According to the Given Polynomial ";
menampilkan_soal(degree,arr,epsilon,evaluate);
cin>>answer;
system("cls");
cout<<"Here is the result : \n";
if(check_answer(answer,find_answer(degree,arr,epsilon,evaluat
e))){
cout <<left << setw(45)<<matches[n_game].p1+" Got 
the Correct Answer!"<<"+"<<weight<<endl;
score_p1=weight;
}
else 
if(check_answer(answer,find_answer(degree,arr,epsilon,evaluate))==f
alse&&abs(answer-find_answer(degree,arr,epsilon,evaluate))<=1e-06){
cout <<left << 
setw(45)<<matches[n_game].p1+"Nearly Got the Correct 
Answer!"<<"+"<<weight/2<<endl;
score_p1=weight/2;
}
else{
cout <<left << setw(45)<<matches[n_game].p1+" Got 
the Wrong Answer!"<<"+0"<<endl;
score_p1=0;
}
if(check_answer(delta,find_answer(degree,arr,epsilon,evaluate
))&&abs(answer-find_answer(degree,arr,epsilon,evaluate))>1e-06){
cout <<left << setw(45)<<matches[n_game].p2+" 
Insert the Correct Answer!"<<"+"<<weight<<endl;
score_p2=weight;
}
else 
if(check_answer(delta,find_answer(degree,arr,epsilon,evaluate))&&ab
s(answer-find_answer(degree,arr,epsilon,evaluate))<=1e-06){
cout <<left << setw(45)<<matches[n_game].p2+" 
Insert the Correct Answer!"<<"+0"<<endl;
score_p2=0;
}
else{
cout <<left << setw(45)<<matches[n_game].p2+" 
Insert the Wrong Answer!"<<"-"<<weight<<endl;
score_p2=-weight;
}
insert_score(matches[n_game].head,score_p1,score_p2,n_game);
system("pause");
system("cls");
cout<<"\t\tThe Challenge Has Ended!";
cout<<"\nHere is the Challenge Result!"<<endl;
match_result(n_game,score_p1_part1,score_p2_part1,score_p1,sc
ore_p2);
cout<<"\nYou Want to Play Again?";
cin>>play_again;
system("pause");
system("cls"); 
if(play_again!='y'){
n_game++;
display_home(n_game);
}
}
}

int main(){
int n_game=0;
display_home(n_game);
return 0;}


