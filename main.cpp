#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h> //pt titlu consola

using namespace std;

ifstream fin; ofstream fout;

struct personal{ //id, nume, sex, varsta, spec(ializare), cabinet
  int id, varsta, cabinet;
  char nume[51], spec[51], sex;
};
struct pacienti{ //id, nume, sex, varsta, boala, medic
  int id, varsta, medic;
  char nume[51], boala[51], sex;
};

string accesStructString(int oc, char strIn[]) {
	string strOut;
	int i=0; while (oc>0) { if (strIn[i]==' ') oc--; i++;}
	while (strIn[i]!=' ' && strIn[i]!=NULL) { strOut+=strIn[i]; i++;}
	return strOut;
}
int accesStructPoz(int oc, char strIn[]) {
	int i=0; while (oc>0) { if (strIn[i]==' ') oc--; i++;}
	return i;
}

void afis() {
  int x, id; string str; char strChar[101];
  system("cls"); SetConsoleTitle("/main()/afis()");
  cout << "1 - Personal" << endl << "2 - Pacienti" << endl;
  int i; cin >> i; system("cls");
  switch (i) {
    case 1: {
      SetConsoleTitle("/main()/afis() - Personal"); fin.open("personal.txt");
      cout << "1 - Dupa ID" << endl << "2 - Dupa ID cabinet" << endl << "3 - Tot personalul" << endl;
      int j; cin >> j; system("cls");
      switch (j) {
        case 1: {SetConsoleTitle("/main()/afis() - Personal - Dupa ID"); cout << "ID: "; cin >> id; system("cls");  while (fin >> x && x!=id) {getline(fin, str);} getline(fin, str); if (x==id) cout << x << str << endl; else cout << "Nu exista personal cu acest ID" << endl; break;}
        case 2: {SetConsoleTitle("/main()/afis() - Personal - Dupa ID cabinet"); cout << "ID cabinet: ";  cin >> id; system("cls");  int g=0; while (fin >> x) {fin.getline(strChar, 101); if (stoi(accesStructString(5, strChar))==id) {cout << x << strChar << endl; g=1;}} if (g==0) cout << "Nu exista cabinet cu acest ID" << endl; break;}
        case 3: {SetConsoleTitle("/main()/afis() - Personal - Tot personalul"); while (fin >> x) {getline(fin, str); cout << x << str << endl;} break;}
        default: afis(); break;
      } break;}
    case 2: {
      SetConsoleTitle("/main()/afis() - Pacienti"); fin.open("pacienti.txt");
      cout << "1 - Dupa ID" << endl << "2 - Dupa ID medic" << endl << "3 - Toti pacientii" << endl;
      int j; cin >> j; system("cls");
      switch (j) {
        case 1: {SetConsoleTitle("/main()/afis() - Pacienti - Dupa ID"); cout << "ID: "; cin >> id; system("cls"); while (fin >> x && x!=id) {getline(fin, str);} getline(fin, str); if (x==id) cout << x << str << endl; else cout << "Nu exista pacient cu acest ID" << endl; break;}
        case 2: {SetConsoleTitle("/main()/afis() - Pacienti - Dupa ID medic"); cout << "ID medic: "; cin >> id; system("cls"); int g=0; while (fin >> x) {fin.getline(strChar, 101); if (stoi(accesStructString(5, strChar))==id) {cout << x << strChar << endl; g=1;}} if (g==0) cout << "Nu exista medic cu acest ID" << endl; break;}
        case 3: {SetConsoleTitle("/main()/afis() - Pacienti - Toti pacientii"); while (fin >> x) {getline(fin, str); cout << x << str << endl;} break;}
        default: afis(); break;
      } break;}
    default: afis(); break;
  }
  fin.close(); system("pause");
}

void modifica() {
  int x, id; string str, y, fileTemp="", charArrStr; char charArr[101];
  system("cls"); SetConsoleTitle("/main()/modifica()");
  cout << "1 - Personal, dupa ID" << endl << "2 - Pacienti, dupa ID" << endl;
  int i; cin >> i; system("cls");
  switch (i) {
    case 1: {
      SetConsoleTitle("/main()/modifica() - Personal, dupa ID"); fin.open("personal.txt");
      cout << "ID: "; cin >> id; system("cls");
      while (fin >> x && x!=id) {getline(fin, str); fileTemp=fileTemp+to_string(x)+str+"\n";}
      fin.getline(charArr,101);
      if (x==id) {
        cout << x << charArr << endl;
        cout << "Ce doresti sa modifici?" << endl << "1 - Nume" << endl << "2 - Sex" << endl << "3 - Varsta" << endl << "4 - Specializare" << endl << "5 - Cabinet" << endl;
        int j; cin >> j; system("cls"); switch (j) {
          case 1: SetConsoleTitle("/main()/modifica() - Personal - Nume"); break;
          case 2: SetConsoleTitle("/main()/modifica() - Personal - Sex"); break;
          case 3: SetConsoleTitle("/main()/modifica() - Personal - Varsta"); break;
          case 4: SetConsoleTitle("/main()/modifica() - Personal - Specializare"); break;
          case 5: SetConsoleTitle("/main()/modifica() - Personal - Cabinet"); break;
          default: modifica(); break;
        }
        cin >> y; charArrStr=charArr;
        charArrStr.replace(accesStructPoz(j,charArr),accesStructString(j,charArr).length(),y);
      }
      else cout << "Nu exista personal cu acest ID" << endl;

      fileTemp=fileTemp+to_string(x)+charArrStr+"\n";
      while (fin >> x) {getline(fin, str); fileTemp=fileTemp+to_string(x)+str+"\n";}
      fin.close(); fout.open("personal.txt"); fout << fileTemp.substr(0, fileTemp.length()-2);
      break;}
    case 2: {
      SetConsoleTitle("/main()/modifica() - Pacienti, dupa ID"); fin.open("pacienti.txt");
      cout << "ID: "; cin >> id; system("cls");
      while (fin >> x && x!=id) {getline(fin, str); fileTemp=fileTemp+to_string(x)+str+"\n";}
      fin.getline(charArr,101);
      if (x==id) {
        cout << x << charArr << endl;
        cout << "Ce doresti sa modifici?" << endl << "1 - Nume" << endl << "2 - Sex" << endl << "3 - Varsta" << endl << "4 - Boala" << endl << "5 - ID medic" << endl;
        int j; cin >> j; system("cls"); switch (j) {
          case 1: SetConsoleTitle("/main()/modifica() - Pacienti - Nume"); break;
          case 2: SetConsoleTitle("/main()/modifica() - Pacienti - Sex"); break;
          case 3: SetConsoleTitle("/main()/modifica() - Pacienti - Varsta"); break;
          case 4: SetConsoleTitle("/main()/modifica() - Pacienti - Boala"); break;
          case 5: SetConsoleTitle("/main()/modifica() - Pacienti - ID medic"); break;
          default: modifica(); break;
        }
        cin >> y; charArrStr=charArr;
        charArrStr.replace(accesStructPoz(j,charArr),accesStructString(j,charArr).length(),y);
      }
      else cout << "Nu exista pacient cu acest ID" << endl;

      fileTemp=fileTemp+to_string(x)+charArrStr+"\n";
      while (fin >> x) {getline(fin, str); fileTemp=fileTemp+to_string(x)+str+"\n";}
      fin.close(); fout.open("pacienti.txt"); fout << fileTemp.substr(0, fileTemp.length()-2);
      break;}
    default: modifica(); break;
  }
  fout.close(); system("pause");
}

void adauga() {
  int y; string x, str;
  system("cls"); SetConsoleTitle("/main()/adauga()");
  cout << "1 - Personal" << endl << "2 - Pacienti" << endl;
  int i; cin >> i; system("cls");
  switch (i) {
    case 1: {
      SetConsoleTitle("/main()/adauga() - Personal");
      fin.open("personal.txt"); while (fin >> y) getline(fin, x); fin.close();
      fout.open("personal.txt", ios::app);
      cout << "ID (urm. " << y+1 << "): "; cin >> x; str=str+x+" ";
      cout << "Nume (ex. Babanu_Marius): "; cin >> x; str=str+x+" ";
      cout << "Sex (ex. M): "; cin >> x; str=str+x+" ";
      cout << "Varsta (ex. 34): "; cin >> x; str=str+x+" ";
      cout << "Specializare (ex. Medic_cardiolog): "; cin >> x; str=str+x+" ";
      cout << "Cabinet (ex. 12): "; cin >> x; str=str+x+" ";
      fout << endl << str;
      break;}
    case 2: {
      SetConsoleTitle("/main()/adauga() - Pacienti");
      fin.open("pacienti.txt"); while (fin >> y) getline(fin, x); fin.close();
      fout.open("pacienti.txt", ios::app);
      cout << "ID (urm. " << y+1 << "): "; cin >> x; str=str+x+" ";
      cout << "Nume (ex. Moisa_Narcisa): "; cin >> x; str=str+x+" ";
      cout << "Sex (ex. F): "; cin >> x; str=str+x+" ";
      cout << "Varsta (ex. 30): "; cin >> x; str=str+x+" ";
      cout << "Boala (ex. Manelofobie): "; cin >> x; str=str+x+" ";
      cout << "ID medic (ex. 123): "; cin >> x; str=str+x+" ";
      fout << endl << str;
      break;}
    default: adauga(); break;
  }
  fout.close(); system("pause");
}

void sterge() {
  int id, x; string str, fileTemp, titlu, file, noId;
  system("cls"); SetConsoleTitle("/main()/sterge()");
  cout << "1 - Personal, dupa ID" << endl << "2 - Pacienti, dupa ID" << endl;
  int i; cin >> i; system("cls");
  switch (i) {
    case 1: {SetConsoleTitle("/main()/sterge() - Personal, dupa ID"); file="personal.txt"; noId="personal"; break;}
    case 2: {SetConsoleTitle("/main()/sterge() - Pacienti, dupa ID"); file="pacienti.txt"; noId="pacient"; break;}
    default: sterge(); break;
  }
  fin.open(file); cout << "ID: "; cin >> id; system("cls");

  while (fin >> x && x!=id) {getline(fin, str); fileTemp=fileTemp+to_string(x)+str+"\n";}
  if (x!=id) cout << "Nu exista " << noId << " cu acest ID" << endl;
  else {getline(fin, str); cout << x << str << endl; while (fin >> x) {getline(fin, str); fileTemp=fileTemp+to_string(x)+str+"\n";}}

  fin.close(); fout.open(file); fout << fileTemp.substr(0, fileTemp.length()-1); fout.close(); system("pause");
}

int creditC=0;
void credit() {
  cout << "  ____             _             _____              _       _ " << endl
       << " |  _ \\  https:// | |  daniel   |  __ \\  - barbu   (_) .cf | |" << endl
       << " | |_) | __ _ _ __| |__  _   _  | |  | | __ _ _ __  _  ___ | |" << endl
       << " |  _ < / _` | '__| '_ \\| | | | | |  | |/ _` | '_ \\| |/ _ \\| |" << endl
       << " | |_) | (_| | |  | |_) | |_| | | |__| | (_| | | | | |  __/| |" << endl
       << " |____/ \\__,_|_|  |_.__/ \\__,_| |_____/ \\__,_|_| |_|_|\\___ |_|" << endl
       << "                                                             " << endl
       << "PROIECT INFORMATICA - Administrare centru de tratament pentru bolnavi cu afectiuni psihice" << endl << "11R2, Colegiul National Bilingv \"George Cosbuc\"" << endl;
  system("pause"); creditC=1;
}

int main() {
  if (creditC==0) credit();
  system("cls"); SetConsoleTitle("/main()");
  cout << "1 - Afiseaza" << endl;
  cout << "2 - Modifica" << endl;
  cout << "3 - Adauga" << endl;
  cout << "4 - Sterge" << endl;
  int i; cin >> i; switch (i) {
    case 1: afis(); break;
    case 2: modifica(); break;
    case 3: adauga(); break;
    case 4: sterge(); break;
  }
  main();
}
