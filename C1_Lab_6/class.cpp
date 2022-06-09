//19.	Создать класс "Граф". Инициализировать первичную структуру графа.
// Разработать методы: добавление вершин графа, удаление вершин графа, 
// построение связей в графе, поиск путей на графе, поиск кратчайшего пути на графе, вывода информации на экран и в файл. 
// Создать массив объектов типа "Граф". Найти граф с минимальным числом узлов.  
#include <iostream>
#include <queue> // очередь
#include <stack> // стек
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
		int ** graf_0; //главный граф
		int ** graf_1; //вспомогательный
		int n; //основное
		int yant = 0; // счётчик
	public:
		Grafs() //иницилизация по умолчанию
		{
			int graf_0 = 1;
		}
		void Graf_create(int x){ //иницилизация первичной структуры графа. 
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
				
		void Graf_another_one(int q){ //добавление вершин	
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
		
		void Graf_bite_the_dust(int w){ //удаление вершин
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

		void Graf_Machine_guns(int i, int j){ //Построение связей
			graf_0[i][j] = 1;
		}
		
		void Graf_ready_to_go(int i, int j){ //разрушение связей
			graf_0[i][j] = 0;
		}
	
		void find_krat(){	//поиск кратчайшего пути на графе
			int quan = 0, p = 0;
			queue<int> Queue;
			Queue.push(0); // помещаем в очередь первую вершину
  			while (!Queue.empty())
  				quan++;
  			int* tops = new int[quan];
			int* nodes = new int[n];
			for (int i = 0; i < n; i++)
    			nodes[i] = 0; // исходно все вершины равны 0
  			Queue.push(0); // помещаем в очередь первую вершину
  			while (!Queue.empty()){ // пока очередь не пуста
    			int node = Queue.front(); // извлекаем вершину
    			Queue.pop();
    			nodes[node] = 2; // отмечаем ее как посещенную
   				for (int j = 0; j < n; j++){ // проверяем для нее все смежные вершины
    				if (graf_0[node][j] == 1 && nodes[j] == 0) { // если вершина смежная и не обнаружена
       					Queue.push(j); // добавляем ее в очередь
        				nodes[j] = 1; // отмечаем вершину как обнаруженную
      				}
    			}	
				cout << node + 1 << endl; // выводим номер вершины
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
		cout << "Введите количество вершин:"
		cin >> n;
		R[i].Graf_create(n)
	}
		if (R[1].quan_tops() > R[2].quan_tops()) max = R[1].quan_tops();
		else max =  R[2].quan_tops();
		if ( max < R[3].quan_tops() ) max = R[3].quan_tops();
		return 0;
}
