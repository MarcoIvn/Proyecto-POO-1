#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class Usuario{
	
	protected:
		string nombre;
		string usuario;
		string password;
	
	public:
		Usuario(){
			nombre = "";
			usuario = "";
			password = "";
		}
		Usuario(string n,string u, string p){
			nombre = n;
			usuario = u;
			password = p;
		}
		string getNombre(){
			return nombre;
		}
		void setNombre(string n){
			nombre = n;
		}
		string getUsuario(){
			return usuario;
		}
		void setUsuario(string u){
			usuario = u;
		}
		string getPassword(){
			return password;
		}
		void setPassword(string p){
			password = p;
		}
};

class Responsable:public Usuario{
	string email;
	
	public:
		Responsable(){
			nombre = "Sin nombre";
			usuario = "";
			password = "";
			email = "Sin registrar";
		}	
		Responsable(string n, string u, string p, string e){
			nombre = n;
			usuario = u;
			password = p;
			email = e;
		}
		string getEmail(){
			return email;
		}
		void setEmail(string e){
			email = e;
		}
	
};

class Cliente{
	string nombre;
	string apellido;
	int edad;
	string telefono;
	string email;
	string sexo;
	string fechamu,fechaent;
	string prueba;
	string resultado;
	//Lab laboratoryc;
	public:
		Cliente(){
			nombre = "Sin nombre";
			apellido = "Sin apellido";
			edad = 1;
			telefono = "*****";
			email = "Sin registrar";
			sexo = "Sin registrar";
			fechamu = "01/01/2021";
			fechaent = "01/01/2021";
			prueba = "Sin prueba";
			resultado = "Sin resultado";
		}	
		string getNombre(){
			return nombre;
		}
		string getApellido(){
			return apellido;
		}
		int getEdad(){
			return edad;
		}
		string getSexo(){
			return sexo;
		}
		string getTelefono(){
			return telefono;
		}
		string getEmail(){
			return email;
		}
		string getFechamu(){
			return fechamu;
		}
		string getFechaent(){
			return fechaent;
		}
		string getPrueba(){
			return prueba;
		}
		string getResultado(){
			return resultado;
		}
	//	Lab getLaboratory(){
	//		return laboratoryc;
	//	}
		void setNombre(string n){
			nombre = n;
		}
		void setApellido(string a){
			apellido = a;
		}
		void setEdad(int e){
			edad = e;
		}
		void setSexo(string sex){
			sexo = sex;
		}
		void setTelefono(string t){
			telefono = t;
		}
		void setEmail(string e){
			email = e;
		}
		void setFechamu(string fmu){
			fechamu = fmu;
		}
		void setFechaent(string fen){
			fechaent = fen;
		}
		void setPrueba(string pp){
			prueba = pp;
		}
		void setResultado(string rr){
			resultado = rr;
		}
	//	void setLaboratory(Lab lc){
	//		laboratoryc = lc;
	//	}
	
};


class Lab{
	string nombreLab, ppcr,pant1,pant2;
	Responsable responsable;
	bool Ppcr, Pantc1, Pantc2;
	vector<string> pruebas; //Vector para guardar las pruebas
	vector<Cliente> clienteslab; //Vector para guardar los clientes
	public:
		Lab(){
			nombreLab = "";
			responsable.setNombre("");
		}
		Lab(string n, Responsable r){
			nombreLab = n;
			responsable = r;
		}
		string getnombreLab(){
			return nombreLab;
		}
		void setnombreLab(string n){
			nombreLab = n;
		}
		Responsable getResponsable(){
			return responsable;
		}
		void setResponsable(Responsable r){
			responsable = r;
		}
		vector<Cliente> getClienteslab(){
			return clienteslab;
		}
		void setClienteslab(vector<Cliente> clb){
			clienteslab = clb;
		}
		bool getPcr(){
			return Ppcr;
		}
		bool getAntcuali(){
			return Pantc1;
		}
		bool getAntcuanti(){
			return Pantc2;
		}
		void setPcr(bool pp){
			Ppcr = pp;
		}
		void setAntCuali(bool pp){
			Pantc1 = pp;
		}
		void setAntCuanti(bool pp){
			Pantc2 = pp;
		}
		
		string Pcr(){   //Metodo para realizar una prueba
			if(Ppcr == false){
				cout<<"No hay prueba de COVID de este tipo";
			}else{
				int randNum = rand()%(2-1 + 1) + 1;
				if(randNum == 2){
					ppcr ="Positivo";
					return ppcr;
				}else{
					ppcr="Negativo";
					return ppcr;
				}
			}
		}	
		string antCuali(){ //Metodo para realizar una prueba
			if(Pantc1 == false){
				cout<<"No hay prueba de COVID de este tipo";
			}else{
				int randNum = rand()%(2-1 + 1) + 1;
				if(randNum == 2){
					pant1="Positivo";
					return pant1;
				}else{
					pant1="Negativo";
					return pant1;
				}		
			}
		}	
		
		string antCuanti(){ //Metodo para realizar una prueba
			if(Pantc2 == false){
				cout<<"No hay prueba de COVID de este tipo";
			}else{
				int randNum = rand()%(10-1 + 1) + 1;
				if(randNum > 2.4){
					pant2="Positivo";
					return pant2;
				}else{
					pant2="Negativo";
					return pant2;
				}			
			}
		}
		void printReport(Cliente cliente){ //Metodo para imprimir todos los datos de Cliente
			
			cout<<"*********Reporte*********"<<endl;
			cout<<"Nombre: "<<cliente.getNombre()<<endl;
			cout<<"Apellido: "<<cliente.getApellido()<<endl;
			cout<<"Edad: "<<cliente.getEdad()<<endl;
			cout<<"Sexo: "<<cliente.getNombre()<<endl;
			cout<<"Telefono: "<<cliente.getTelefono()<<endl;
			cout<<"Email: "<<cliente.getEmail()<<endl;
			cout<<"Fecha de muestra: "<<cliente.getFechamu() <<endl;
			cout<<"Fecha de Entrega de resultados: "<<cliente.getFechaent()<<endl;
			cout<<"Prueba: "<<cliente.getPrueba()<<endl;
			cout<<"Resultado: "<<cliente.getResultado()<<endl;
		}
};


class Superadmin : public Usuario{
	
	vector<string> listLab; //Vector que incluye lis laboratorios creados por el superadmin
	
	public:
		Superadmin(){
			usuario = "";
			password = "";
		}
		Superadmin(string u,string p){
			usuario = u;
			password = p;
		}
		void Crearlab(Lab l){
			listLab.push_back(l.getnombreLab());
		}
		void ListLab(){
			cout<<"Laboratorios"<<endl;
			for(int i = 0;i < listLab.size();i++){
				cout<<"-"<<listLab[i]<<endl;
			}
		}
		vector<string> getListLab(){
			return listLab;
		}
		/*
		void BorrarLab(Lab l){
			Responsable r;
			string nl;
			r = l.getResponsable();
			r.setNombre("");
			r.setUsuario("");
			r.setPassword("");
			l.setnombreLab("");
			l.setResponsable(r);
			nl = l.getnombreLab();
			for(int i = 0;i < listLab.size();i++){
				if(nl == listLab[i]){
					//listLab.erase(nl);    Checar
				}else{
					cout<<"No se encontro el laboratorio"<<endl;	
				}
			}
		}
		*/
};



int main(){
	int ans,cc,a,b,c,dd,pp;
	string anst,user,pass,sa,sau,sap,r1,r1u,r1p,r2,r2u,r2p;
	Superadmin SuperAdmin;
	SuperAdmin.setNombre("Poncho Perez");
	SuperAdmin.setUsuario("Poncho123");  
	SuperAdmin.setPassword("gato55779"); 
	vector<string> users,passwords;
	vector<Responsable> responsables;
	vector<Lab> laboratories;
	//vector<Cliente> clientes;
	vector<Cliente> clientes;
	users.push_back(SuperAdmin.getUsuario());
	passwords.push_back(SuperAdmin.getPassword());
	
	sa = SuperAdmin.getNombre();
	sau = SuperAdmin.getUsuario();
	sap = SuperAdmin.getPassword();
	
	b = 0;   //Variables para inicializar y romper whiles
	a = 0;
	c = 0;
	cc = 0;
	dd = 0;
	pp = 0;
	while(cc == 0){
		cout<<""<<endl;
		cout<<"****************Menu***************"<<endl;
		cout<<"1- Login"<<endl;
		cout<<"2- End"<<endl;
		cout<<"***********************************"<<endl;
		cout<<"Elige la opción"<<endl;
		cin>>ans;
		
		switch(ans){
			case 1: 
				b = 0;
				a = 0;
				c = 0;
				cc = 0;
				dd = 0;
				pp = 0;
				while(c == 0){
					while(a == 0){
						dd = 0;
						cout<<"Escriba su nombre de usuario: ";	
						cin>>anst;
						while(dd == 0){
							for(int i=0; i<users.size();i++){ //For para encontrar si el string dado pertenece a un nombre de usuario en el array users
								if(anst != users[i]){
									pp = 0;	
								}else{
									pp = 1;
									break;
								}
							}
							if(pp == 0){
								cout<<"No ha ingresado un nombre de usuario valido, intentelo de nuevo"<<endl;
								dd = 1;
							}else{
								dd = 1;
								a = 1;
							}
						}
					}
					a = 0;
					if(anst == sau){
						while(a == 0){
							cout<<"Ingrese su contraseña: ";
							cin>>pass;
							if(pass != sap ){  //Evaluar si la contraseña ingresada es del SuperAdmin para asi acceder a todas sus funciones
								cout<<"No ha ingresado la contraseña valida, intentelo de nuevo"<<endl;
							}else{
								a = 1;
							}	
						}
						cout<<"Sesion iniciada correctamente";
						b = 0;
						while(b == 0){
							cout<<""<<endl;
							cout<<"****************Menu***************"<<endl;
							cout<<"1- Crear Lab"<<endl;
							cout<<"2- Enlistar Lab"<<endl;
							//cout<<"3- Borrar Lab"<<endl;
							cout<<"3- Salir"<<endl;
							cout<<"***********************************"<<endl;
							cout<<"Elige la opción"<<endl;
							cin>>ans;	
							if(ans == 1){
								Lab laboratory;
								Responsable responsableLab;
								string nl,nr,ru,rp,sino;
								int k = 0;
								cout<<"Ingresa el nombre del laboratorio"<<endl;
								cin>>nl;
								cout<<"Ingresa el nombre del responsable que desea asignar"<<endl;
								cin>>nr;
								cout<<"Ingresa el nombre de usuario del responsable"<<endl;
								cin>>ru;
								cout<<"Ingresa la contraseña del responsable"<<endl;
								cin>>rp;
								while(k == 0){
									cout<<"En el laboratorio hay pruebas PCR?: Diga si o no"<<endl;
									cin>>sino;
									if(sino == "si"){
										laboratory.setPcr(true);
										k = 1;
									}else if(sino == "no"){
										laboratory.setPcr(false);
										k = 1;
									}else{
										cout<<"No dio una respuesta valida"<<endl;
									}	
								}
								k = 0;
								while(k == 0){
									cout<<"En el laboratorio hay pruebas de Antigenos Cualitativos?: Diga si o no"<<endl;
									cin>>sino;
									if(sino == "si"){
										laboratory.setAntCuali(true);
										k = 1;
									}else if(sino == "no"){
										laboratory.setAntCuali(false);
										k = 1;
									}else{
										cout<<"No dio una respuesta valida"<<endl;
									}	
								}
								k = 0;
								while(k == 0){
									cout<<"En el laboratorio hay pruebas de Antigenos Cuantitativos?: Diga si o no"<<endl;
									cin>>sino;
									if(sino == "si"){
										laboratory.setAntCuanti(true);
										k = 1;
									}else if(sino == "no"){
										laboratory.setAntCuanti(false);
										k = 1;
									}else{
										cout<<"No dio una respuesta valida"<<endl;
									}	
								}
								laboratory.setnombreLab(nl);
								responsableLab.setNombre(nr);
								responsableLab.setUsuario(ru);
								users.push_back(ru);
								responsableLab.setPassword(rp);
								passwords.push_back(rp);
								laboratory.setResponsable(responsableLab);
								responsables.push_back(responsableLab);
								laboratories.push_back(laboratory);
								SuperAdmin.Crearlab(laboratory);
							}else if(ans == 2){
								SuperAdmin.ListLab();
							}/*else if(ans == 3){
								string nl;
								cout<<"Ingrese el nombre del laboratorio que desee borrar: "<<endl;
								cin>>nl;*/
							/*}*/else if(ans == 3){
								b = 1;
								c = 1;
								cc = 0;
							}
						}
					}
					else if(anst != sau){
						string paas;
						a = 0;
						dd = 0;
						for(int i = 0;i<responsables.size();i++){    //For para checar si la contraseña ingresada pertenece al nombre de usuario en el mismo indice de los arrays users y passwords
							if(anst == responsables[i].getUsuario()){
								paas = responsables[i].getPassword();
								break;
							}
						}
						while(a == 0){
							cout<<"Ingrese su contraseña: ";
							cin>>pass;
							if(pass == paas){
								break;
							}
							while(dd == 0){
								if(pass == paas){
									pp = 1;
									a = 1;
								}else{
									cout<<"No ha ingresado la contraseña valida, intentelo de nuevo"<<endl;
									dd = 1;
								}
							}
						}
						Responsable tt;
						Lab labr;
						for(int i = 0;i<laboratories.size();i++){
							tt = laboratories[i].getResponsable();		
							if(pass == tt.getPassword()){
								labr = laboratories[i];
								break;	
							}
						}
						string pcr,ant1,ant2;		//Strings para checar la disponibilidad de las pruebas en el laboratorio
						if(labr.getPcr() == true){
							pcr = "Disponible";	
						}else{
							pcr = "Sin disponibilidad";
						}
						if(labr.getAntcuali() == true){
							ant1 = "Disponible";	
						}else{
							ant1 = "Sin disponibilidad";
						}
						if(labr.getAntcuanti() == true){
							ant2 = "Disponible";	
						}else{
							ant2 = "Sin disponibilidad";
						}
						cout<<"Sesion iniciada correctamente"<<endl;
						b = 0;
						while(b == 0){
							cout<<"******Pruebas disponibles******"<<endl;
							cout<<"1- PCR: "<<pcr<<endl;
							cout<<"2- Antigenos Cualitativos: "<<ant1<<endl;
							cout<<"3- Antigenos Cuantitativos: "<<ant2<<endl;
							cout<<"*******************************"<<endl;
							
							cout<<"******Menu******"<<endl;
							cout<<"1- Registrar Prueba: "<<endl;
							cout<<"2- Listar Pruebas: "<<endl;
							cout<<"3- Salir: "<<endl;
							cout<<"****************"<<endl;
							
							cout<<""<<endl;
							cout<<"Elige una opcion: "<<endl;
							cin>>ans;
							if(ans == 1){
								string anss;
								int an;
								int g = 0;
								Cliente clientel;
								cout<<"Ingrese el nombre del Cliente: "<<endl;
								cin>>anss;	
								clientel.setNombre(anss);
								cout<<"Ingrese el apellido del Cliente: "<<endl;
								cin>>anss;
								clientel.setApellido(anss);
								cout<<"Ingrese la edad del Cliente: "<<endl;
								cin>>an;
								clientel.setEdad(an);
								cout<<"Ingrese el sexo del Cliente: "<<endl;
								cin>>anss;
								clientel.setSexo(anss);
								cout<<"Ingrese el telefono del Cliente: "<<endl;
								cin>>anss;
								clientel.setTelefono(anss);
								cout<<"Ingrese el email del Cliente: "<<endl;
								cin>>anss;
								clientel.setEmail(anss);
								while(g == 0){
									cout<<"Que prueba se realizara(cheque las pruebas disponibles en este laboratorio): "<<endl;
									cin>>an;
									switch(an){
										case 1: 
											if(labr.getPcr() == true){
												clientel.setPrueba("PCR");
												g = 1;
											}else if(labr.getPcr() == false){
												cout<<"Sin disponibilidad, elija otra prueba"<<endl;
											}
										break;
										case 2:
											if(labr.getAntcuali() == true){
												clientel.setPrueba("Antigenos Cualitativos");
												g = 1;
											}else if(labr.getAntcuali() == false){
												cout<<"Sin disponibilidad, elija otra prueba"<<endl;
											}
										break;
										case 3:
											if(labr.getAntcuanti() == true){
												clientel.setPrueba("Antigenos Cuantitativos");
												g = 1;
											}else if(labr.getAntcuanti() == false){
												cout<<"Sin disponibilidad, elija otra prueba"<<endl;
											}
										break;
									}	
								}
								//metodo
								cout<<"Ingrese la fecha de muestra de resultados: "<<endl;
								cin>>anss;
								clientel.setFechamu(anss);
								cout<<"Ingrese la fecha de entrega de resultados: "<<endl;
								cin>>anss;
								clientel.setFechaent(anss);
								if(clientel.getPrueba() == "PCR"){
									clientel.setResultado(labr.Pcr());
								}else if(clientel.getPrueba() == "Antigenos Cualitativos"){
									clientel.setResultado(labr.antCuali());
								}else if(clientel.getPrueba() == "Antigenos Cuantitativos"){
									clientel.setResultado(labr.antCuanti());
								}
								clientes.push_back(clientel);
								labr.setClienteslab(clientes);
								
							}else if(ans==2){
								clientes = labr.getClienteslab();
								for(int i =0;i<clientes.size();i++){
									labr.printReport(clientes[i]);
								}	
							}else{
								c = 1;
								b = 1;
								cc = 0;
							}
						}
					}
				}
			
			break;
			case 2: 
				cout<<"Tenga un buen día :)";
				cc = 1;
			break;	
		}
	}	
	return 0;
}
// cin.get(); system("cls"); 
