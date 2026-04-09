#include <iostream>
#include <vector>
#include <set>
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
//Con esta funcion vamos a obtener un set a partir de la matriz de relaciones
set<pair<int,int>> Convertion(const vector <vector<int>> &M){
    set <pair<int,int>> Relation;
    for(size_t i=0;i<M.size();i++){
        Relation.insert({M[i][0],M[i][1]});
    }
    return Relation;
}

//O(n*l)
bool Reflexive(const set <pair<int,int>> & Set, const vector <int> &S){
    //Para cada elemento en S recorro el set buscando que exista la tupla (S[i],S[i]) para todos los elementos del set
    for(size_t i=0;i<S.size();i++){
        if(!Set.count({S[i],S[i]})){
            return false;
        }
        }
        return true;
} 
//La lógica es practicamente la misma que la de reflexiva solo que aqui si encuentro alguna tupla (s[i],s[i]) pues ya no puede ser irreflexiva
//Note que una no es estrictamente la negación de la otra por lo que se puede dar el caso de una relacion binaria no reflexiva y no irreflexiva por lo que es necesario tener las dos programadas
bool Irreflexive(const set <pair<int,int>> &Set, const vector <int> &S){
    for(size_t i=0;i<S.size();i++){
       if(Set.count({S[i],S[i]})){
        return false;
       } 
    }
    return true;
}
//O(l*logl)
bool Symmetry(const vector <vector<int>> &M, const set <pair<int,int>> &Set){
    //iteramos sobre los elementos de la matriz
    for (size_t i = 0; i < M.size(); i++){
        //si no existe la tupla simetrica para cada elemento de la matriz retornamos false
        if(!Set.count({M[i][1],M[i][0]})){
            return false;
        }
        }
        return true;
    }

// O(l^2*logl)
bool Transitive(const vector <vector<int>> &M, const set <pair<int,int>> &Set){
    //fijamos la i-esima fila
    for (size_t i = 0; i < M.size(); i++){
        for (size_t j = 0; j < M.size(); j++){
            //si existe alguna tupla que empiece con la segunda entrada de la i-esima fila entonces tenemos que encontrar la tupla que las hace transitivas
            //entonces para eso buscamos en el set la primera entrada de la i-ésima y la segunda entrada de la j-ésima, si no existe retornamos false
            if(M[j][0]==M[i][1] && !Set.count({M[i][0],M[j][1]})){
                return false;
             }
        }
    }
    return true;
}

int main(){
cout<<"Primer codigo de Teoria de Conjuntos; propiedades de relaciones binarias"<<endl;
int n,m;
cout<<"Ingrese la cardinalidad del conjuto"<<endl;
cin>>n;
vector <int> Nums(n);
Capture_Set(Nums);
cout<<"El conjunto es:"<<endl;
for(size_t i=0;i<Nums.size();i++){
    cout<<Nums[i]<<" ";
}
cout<<endl;
cout<<"Ingrese la cardinalidad de la relacion: "<<endl;
cin>>m;
vector <vector<int>> Relation(m,vector<int>(2));
Capture_BinRelation(Relation);
//Transformamos la matriz en un set de pares una sola vez
set <pair<int,int>> Set = Convertion(Relation);

cout<<"La matriz de relacion es: "<<endl;
for (size_t i = 0; i< Relation.size(); i++){
    for (size_t j = 0; j < Relation[i].size(); j++){
        cout<<Relation[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;

if(Reflexive(Set,Nums)){
    cout<<"La relacion es reflexiva"<<endl;
}
if(Irreflexive(Set,Nums)){
    cout<<"La relacion es irreflexiva"<<endl;
}
if(Symmetry(Relation,Set)){
    cout<<"La relacion es simetrica"<<endl;
}
if(Transitive(Relation,Set)){
    cout<<"La relacion es transitiva"<<endl;
}
return 0;
};
