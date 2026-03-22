#include <iostream>
#include <vector>
using namespace std;
//Relacion Binaria. primer c�digo Teor�a de Conjuntos
//En funciones cuando se pasa como parametro const indica solo lectura, es decir, es un apuntador pero no permite modificar lo que se pasó como parámetro :)
void Capture_Set(vector <int> &S){
    cout<<"Capture el conjunto: "<<endl;
    for(size_t i=0;i<S.size();i++){
        cin>>S[i];
    }
}
void Capture_BinRelation(vector <vector<int>> &M){
    for (size_t i = 0; i < M.size(); i++){
        for(size_t j=0;j<M[i].size();j++){
            cout<<"Elemento ["<<i<<"]["<<j<<"]"<<endl;
            cin>>M[i][j];
        }
    }
    
}
//O(n*l)
bool Reflexive(const vector <vector<int>> &M, const vector <int> &S){
    //Para cada elemento en el set recorro la matriz como tuplas, ya que sé que solo hay dos columnas y verifico que exista la tupla (S[i],S[i]) para todos los elementos del set
    for(size_t i=0;i<S.size();i++){
        //Inicializamos un bool en false que indica si existe la tupla de relación 
        bool existence=false;
        for(size_t j=0;j<M.size();j++){
        if( M[j][0]==S[i] && M[j][1]==S[i]){
            //si la tupla existe marcamos existencia y rompemos el ciclo porque ya no aporta nada seguir buscando
            existence= true; 
            break;   
        }
        }
         if(!existence){
            return false;
        }   
        }
        return true;
} 
//La lógica es practicamente la misma que la de reflexiva solo que aqui si encuentro alguna tupla (s[i],s[i]) pues ya no puede ser irreflexiva
//Note que una no es estrictamente la negación de la otra por lo que se puede dar el caso de una relacion binaria no reflexiva y no irreflexiva por lo que es necesario tener las dos programadas
bool Irreflexive(const vector <vector<int>> &M, const vector <int> &S){
    for(size_t i=0;i<S.size();i++){
        for (size_t j = 0; j <M.size(); j++){
           if( M[j][0]==S[i] && M[j][1]==S[i]){
            return false;
        }  
        }
        
    }
    return true;
}
//Estoy consciente de que esto busca doble vez por cada tupla si existe la simetria de esa tupla (primero que quede bien hecha y ya luego la optimizo ) O(l^2
bool Simmetry(const vector <vector<int>> &M){
    //fijamos el i-ésimo elemento y creamos el bool que nos indicará si existe la tupla simétrica
    for (size_t i = 0; i < M.size(); i++){
        bool simmetric= false;
        //buscamos desde el principio de la matriz a la tupla simétrica
        for (size_t j = 0; j < M.size(); j++){
            //si existe entonces hacemos true el booleano 
            if (M[i][0]==M[j][1] && M[i][1]==M[j][0]){
                simmetric= true;
                break;
            }
        }
        //si no existe ya rifamos
            if(!simmetric){
                return false;
            }
    }
    return true;
}
//Esta madre también tiene un tiempo de operación muy grande, pero la hago y ahorita pienso como lo puedo reducir O(l^3)
bool Transitive(const vector <vector<int>> &M){
    //fijamos la i-esima fila
    for (size_t i = 0; i < M.size(); i++){
        for (size_t j = 0; j < M.size(); j++){
            //si existe alguna tupla que empiece con la segunda entrada de la i-esima fila entonces tenemos que encontrar la tupla las hace transitivas
            if(M[j][0]==M[i][1]){
                bool triple=false;
                for (size_t k = 0; k < M.size(); k++){
                    //si existe marcamos check y rompemos el ciclo
                    if(M[k][0]==M[i][0] && M[k][1]==M[j][1]){
                        triple=true;
                        break;
                    }           
                 }
                 //si no existe ya rifamos
                 if(!triple){
                    return false;
                 }
             }
        }
    }
    return true;
}




int main(){
cout<<"Primer aproximacion para el codigo"<<endl;
int n,m;
cout<<"Ingrese el tamano del conjuto"<<endl;
cin>>n;
vector <int> Nums(n);
Capture_Set(Nums);
cout<<"El vector es:"<<endl;
for(size_t i=0;i<Nums.size();i++){
    cout<<Nums[i]<<" ";
}
cout<<endl;
cout<<"Ingrese la cardinalidad de la relacion"<<endl;
cin>>m;
vector <vector<int>> Relation(m,vector<int>(2));
Capture_BinRelation(Relation);
for (size_t i = 0; i< Relation.size(); i++)
{
    for (size_t j = 0; j < Relation[i].size(); j++)
    {
        cout<<Relation[i][j]<<" ";
    }
    
}
cout<<endl;

if(Reflexive(Relation,Nums)){
    cout<<"La relacion es reflexiva"<<endl;
}
if(Irreflexive(Relation,Nums)){
    cout<<"La relacion es irreflxiva"<<endl;
}
if(Simmetry(Relation)){
    cout<<"La relacion es simetrica"<<endl;
}
if(Transitive(Relation)){
    cout<<"La relacion es transitiva"<<endl;
}
return 0;
};