//19.	������� ����� "����". ���������������� ��������� ��������� �����.
// ����������� ������: ���������� ������ �����, �������� ������ �����, 
// ���������� ������ � �����, ����� ����� �� �����, ����� ����������� ���� �� �����, ������ ���������� �� ����� � � ����. 
// ������� ������ �������� ���� "����". ����� ���� � ����������� ������ �����.  
#include <iostream>
#include <queue> // �������
#include <stack> // ����
#include <fstream>
using namespace std;
const char * dir = "Q:\\MYFiles\\work_space\\lab\\lab_6\\rec_1_graf.txt";
const char * dir2 = "Q:\\MYFiles\\work_space\\lab\\lab_5\\test2.txt";
void Graf_create(int x);
void Graf_fill();
void Graf_another_one(int q);
void Graf_bite_the_dust(int w);
void Graf_Machine_guns(int i, int j);
void Graf_ready_to_go(int i, int j);
void find_krat();
int quan_tops();
class Grafs{
	private:
		int ** graf_0; //������� ����
		int ** graf_1; //���������������
		int n; //��������
		int yant = 0; // �������
	public:
		Grafs() //������������ �� ���������
		{
			int graf_0 = 1;
		}
		void Graf_create(int x){ //������������ ��������� ��������� �����. 
			n = x;
			graf_0 = new int*[n];
			for(int i = 0; i <n; i++){
				graf_0[i] = new int[n];
			}
			Graf_fill();
		}
			
		void Graf_fill(){
			for(int i = 0; i <n; i++){
				for(int j=0; j < n; j++)
					std::cin>>graf_0[i][j];
			}
		}
				
		void Graf_another_one(int q){ //���������� ������	
			graf_1=new int*[n+q];
			for(int i=0;i<n+q;i++)
				graf_1=new int*[n+q];
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					graf_1[i][j] = graf_0[i][j];
			}
			for(int i=n;i<n+q;i++){
				for(int j=n;j<n+q;j++)
					std::cin>>graf_1[i][j];
			}

			for (int i = 0; i < n; i++)
        		delete [] graf_0[i];
   			delete [] graf_0;
   			n = n + q;
			Graf_create(n);
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					graf_0[i][j] = graf_1[i][j];
			}
		}
		
		void Graf_bite_the_dust(int w){ //�������� ������
			graf_1=new int*[n-1];
			for(int i=0;i<n;i++){
				if(i != w)
					graf_1=new int*[n-1];
				else{
					n--;
					i--;
				}
			}
			for(int i=0;i<n;i++){
				if(i != w){
					for(int j=0;j<n;j++){
						if (j != w)
							graf_1[i][j] = graf_0[i][j];
					}
				}
			}
			for (int i = 0; i < n; i++)
        		delete [] graf_0[i];
        	Graf_create(n);
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					graf_0[i][j] = graf_1[i][j];
			}
		}

		void Graf_Machine_guns(int i, int j){ //���������� ������
			graf_0[i][j] = 1;
		}
		
		void Graf_ready_to_go(int i, int j){ //���������� ������
			graf_0[i][j] = 0;
		}
	
		void find_krat(){	//����� ����������� ���� �� �����
			int quan = 0, p = 0;
			queue<int> Queue;
			Queue.push(0); // �������� � ������� ������ �������
  			while (!Queue.empty())
  				quan++;
  			int* tops = new int[quan];
			int* nodes = new int[n];
			for (int i = 0; i < n; i++)
    			nodes[i] = 0; // ������� ��� ������� ����� 0
  			Queue.push(0); // �������� � ������� ������ �������
  			while (!Queue.empty()){ // ���� ������� �� �����
    			int node = Queue.front(); // ��������� �������
    			Queue.pop();
    			nodes[node] = 2; // �������� �� ��� ����������
   				for (int j = 0; j < n; j++){ // ��������� ��� ��� ��� ������� �������
    				if (graf_0[node][j] == 1 && nodes[j] == 0) { // ���� ������� ������� � �� ����������
       					Queue.push(j); // ��������� �� � �������
        				nodes[j] = 1; // �������� ������� ��� ������������
      				}
    			}	
				cout << node + 1 << endl; // ������� ����� �������
				tops[p] = node + 1; 
				p++;
			}	
				std::ofstream rec(dir);
				for(int i = 0; i < p; i++){
					rec << tops[i];
				}
			rec.close();
  			cin.get();
			}
		
		int quan_tops(){
			return n;	
		}
		
		
};
int main(){
	int n, max;
	Grafs R[3];
	for(int i = 0; i < 3; i++){
		cout << "������� ���������� ������:"
		cin >> n;
		R[i].Graf_create(n)
	}
		if (R[1].quan_tops() > R[2].quan_tops()) max = R[1].quan_tops();
		else max =  R[2].quan_tops();
		if ( max < R[3].quan_tops() ) max = R[3].quan_tops();
		return 0;
}
