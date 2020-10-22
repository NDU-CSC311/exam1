#include <iostream>
#include "FA.h"
#include "utils.h"


int main(int argc,char **argv){

if(auto n=readFA(argv[1])){
   FA nfa=*n;
   std::cout<<"digraph finite_state_machine {\nrankdir=LR;\nsize=\"8,5\"\n";
  std::cout<<"node [shape = doublecircle];";
   for(auto s:nfa.accepting()){
	  std::cout<<s<<" "; 
	}
   	std::cout<<";\nnode [shape = circle];\n";
   std::cout<<"DUMMY [style=\"invis\"];\n";
   std::cout<<"DUMMY -> "<<nfa.starting() <<";\n";
   for(auto [k,v]:nfa.transitions()){
	for(auto x:v){
	std::cout<<k.first<<"->"<<x<<"[ label = \""<<k.second<<"\" ];\n";
	}	

   }
   std::cout<<"}\n";
}
else
std::cout<<"error\n";

}


