#include<bits/stdc++.h>
using namespace std;
class Variable;
class Process {
	public:
	string processName;
	vector<Variable*> variables;
	int allocatedMemory;
	
	Process(string processName){
		this->processName = processName;
		this->allocatedMemory = 0;
	}
};

class Variable{
	public:
	Process* processToWhichIsAllocated;
	string variableName; 
	int blocksAssigned;
	vector<int> listOfMemoryBlocksAllocated;
	
	Variable(Process* processToWhichIsAllocated,string variableName,int blocksAssigned ){
		this->processToWhichIsAllocated = processToWhichIsAllocated;
		this->variableName = variableName;
		this->blocksAssigned = blocksAssigned;
	}
};


class MemoryManager{
	public:
	vector<int> blocksOfMemory;
	int size;
	int currentFreeBlocksCount;
	vector<bool> isCurrentBlockFree;
	map<string, Process*> processes;
//	map<string, Process*> memoryAllocatedToProcesses;
	
	public:
		MemoryManager(int size){
			this->size = size;
			blocksOfMemory = vector<int> (size, 0);
			isCurrentBlockFree = vector<bool>(size, true);
			this->currentFreeBlocksCount = size;
		}
		
		bool allocationStrategy(Process* &p, int blocksRequested, bool isContigousBlocksRequired, Variable* &v){
			int allocatedBlocks = 0;
			vector<int> listOfMemoryBlocksAllocated;
			if(isContigousBlocksRequired){
				for(int index = 0;index < this->size; index++){
					if(isCurrentBlockFree[index]){
						allocatedBlocks = 1;
						
						listOfMemoryBlocksAllocated.push_back(index);
						int j = index+1;
						for(j=index+1;j<this->size;j++){
							if(isCurrentBlockFree[j] == false){
								allocatedBlocks = 0;
								break;	
							} else {
								listOfMemoryBlocksAllocated.push_back(j);
								allocatedBlocks++;
							}
							if(allocatedBlocks == blocksRequested){
								p->allocatedMemory += blocksRequested;
								v->processToWhichIsAllocated = p;
								v->listOfMemoryBlocksAllocated = listOfMemoryBlocksAllocated;
								p->variables.push_back(v);
								this->currentFreeBlocksCount -= blocksRequested;
								this->processes[p->processName] = p;
								// mark as allocated also
								
								for(int i=0;i<listOfMemoryBlocksAllocated.size();i++){
									isCurrentBlockFree[listOfMemoryBlocksAllocated[i]] = false;
								}
								return true;
							}
						}
					} 
					else {
						allocatedBlocks=0;
						listOfMemoryBlocksAllocated.clear();
					}
				}
			} 
			else {
						vector<int> listOfMemoryBlocksAllocated;
						for(int index = 0; index< this->size;index++){
							
							if(isCurrentBlockFree[index]){
//								cout<<"Index : "<<index<<endl;
								listOfMemoryBlocksAllocated.push_back(index);
								isCurrentBlockFree[index] = false;
								allocatedBlocks++;
							}
							if(allocatedBlocks == blocksRequested){
								p->allocatedMemory += blocksRequested;
								v->processToWhichIsAllocated = p;
								v->listOfMemoryBlocksAllocated = listOfMemoryBlocksAllocated;
								p->variables.push_back(v);
								this->currentFreeBlocksCount -= blocksRequested;
								this->processes[p->processName] = p;
								return true;
							}
							
						}
						return false;
					}
		}
		
		bool allocate(Process* &p1, string variableName, int blocksRequested, bool isContigousBlocksRequired, Variable* &v){
			if(blocksRequested > this->currentFreeBlocksCount){
				return false;
			}
			return allocationStrategy(p1,blocksRequested,isContigousBlocksRequired, v);
		}
		
		bool free(Process* &p1, string variableName){
			if(processes.find(p1->processName) == processes.end()){
				cout<<"Process does not exist";
				return false;
			}
			Process* process = processes[p1->processName];
			for(int i=0;i<process->variables.size();i++){
				Variable* v = process->variables[i];
				if(v->variableName == variableName){
					this->currentFreeBlocksCount += v->blocksAssigned;
					v->blocksAssigned = 0;
					v->processToWhichIsAllocated = NULL;
					return true;
				}
			}
			return false;
		} 
		
		bool kill(Process* p1){
			if(processes.find(p1->processName) == processes.end()){
				cout<<"Process does not exist";
				return false;
			}
			Process* process = processes[p1->processName];
			bool hasAnyVariablesRemoved = false;
			for(int i=0;i<process->variables.size();i++){
				Variable* v = process->variables[i];
				this->currentFreeBlocksCount += v->blocksAssigned;
				v->blocksAssigned = 0;
				v->processToWhichIsAllocated = NULL;
				hasAnyVariablesRemoved = true;
			}
			return hasAnyVariablesRemoved;
		}
		
		void inspect(Process* p1){
			cout<<"Process Name : " <<p1->processName<<endl;
			cout<<"Blocks Allocated to Process : " <<p1->allocatedMemory<<endl;
			cout<<" Variables under the process are: "; 
			for(int i=0;i<p1->variables.size();i++){
				Variable* v = p1->variables[i];
				if(v->blocksAssigned > 0){
					cout<<"Variable Name"<<v->variableName<<endl;
					for(int i=0;i<v->listOfMemoryBlocksAllocated.size();i++){
						cout<<v->listOfMemoryBlocksAllocated[i]<<" ";
					}
					cout<<endl;
				}
			}
		}
};


int main(){
	int memorySize = 100;
//	cin>>memorySize;
		int requestedBlocks =10; 
		string variableName = "var_x";
		string processName = "p1";
//		cout<< "Enter the requested Block size";
//		cin>>requestedBlocks;
//		cout<<"Enter variable name";
//		cin>>variableName;
//		cout<<"Enter process name ";
//		cin>> processName;
		MemoryManager* memoryManager = new MemoryManager(memorySize);
		Process* p1 = new Process(processName);
		Variable* var_x = new Variable(p1,variableName, requestedBlocks);
		bool success = memoryManager->allocate(p1,variableName, requestedBlocks,true,var_x);
		if(success){
			cout<<"Success ";
			cout<< requestedBlocks<<" "<< memoryManager->currentFreeBlocksCount<<endl;
		} else {
			cout<<"Error"<<endl;
		
			}
//		memoryManager->inspect(p1);
		
		Process* p2 = new Process("p2");
		cout<<endl;
		int r1 = 60; 
		Variable* var_1 = new Variable(p2,"r1", r1);
		bool successR1 = memoryManager->allocate(p2,"r1", r1,false,var_1);
		if(successR1){
			cout<< r1<<" "<< memoryManager->currentFreeBlocksCount;
		} else {
			cout<<"Error"<< "0" <<" "<< memoryManager->currentFreeBlocksCount<< endl;
		}
		
		cout<<endl;
		int r2 = 20; 
		Variable* var_2 = new Variable(p2,"r2", r2);
		bool successR2 = memoryManager->allocate(p2,"r2", r2,false,var_2);
		if(successR2){
			cout<< r2<<" "<< memoryManager->currentFreeBlocksCount;
		} else {
			cout<<"Error"<< "0" <<" "<< memoryManager->currentFreeBlocksCount<< endl;
		}

		cout<<endl;
		int requestedBlocksP3 = 10; 
		Variable* var_z = new Variable(p2,"var_z", requestedBlocksP3);
		bool successP3 = memoryManager->allocate(p2,"var_z", requestedBlocksP3,false,var_z);
		if(successP3){
			cout<< requestedBlocksP3<<" "<< memoryManager->currentFreeBlocksCount;
		} else {
			cout<<"Error"<< "0" <<" "<< memoryManager->currentFreeBlocksCount<< endl;
		}
		
//		int requestedBlocksP4 = 10; 
//		Variable* var_w = new Variable(p2,"var_w", requestedBlocksP4);
//		bool successP4 = memoryManager->allocate(p2,"var_w", requestedBlocksP4,false,var_w);
//		if(successP4){
//			cout<< requestedBlocksP3<<" "<< memoryManager->currentFreeBlocksCount;
//		} else {
//			cout<<"Error"<< "0" <<" "<< memoryManager->currentFreeBlocksCount<< endl;
//		}
//		
		memoryManager->inspect(p2);
		bool freeSuccess = memoryManager->free(p2,"r1");
		if(freeSuccess){
			cout<<"Memory Removed"<<endl;
			memoryManager->inspect(p2);
		}
		
		
}