#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string elements[120] = {
    "H 1.008",
    "He 4.0026",
    "Li 6.94",
    "Be 9.0122",
    "B 10.81",
    "C 12.011",
    "N 14.007",
    "O 15.999",
    "F 18.998",
    "Ne 20.180",
    "Na 22.990",
    "Mg 24.305",
    "Al 26.982",
    "Si 28.085",
    "P 30.974",
    "S 32.06",
    "Cl 35.45",
    "Ar 39.948",
    "K 39.098",
    "Ca 40.078",
    "Sc 44.956",
    "Ti 47.867",
    "V 50.942",
    "Cr 51.996",
    "Mn 54.938",
    "Fe 55.845",
    "Co 58.933",
    "Ni 58.693",
    "Cu 63.546",
    "Zn 65.38",
    "Ga 69.723",
    "Ge 72.63",
    "As 74.922",
    "Se 78.96",
    "Br 79.904",
    "Kr 83.798",
    "Rb 85.468",
    "Sr 87.62",
    "Y 88.906",
    "Zr 91.224",
    "Nb 92.906",
    "Mo 95.96",
    "Tc 97.91",
    "Ru 101.07",
    "Rh 102.91",
    "Pd 106.42",
    "Ag 107.87",
    "Cd 112.41",
    "In 114.82",
    "Sn 118.71",
    "Sb 121.76",
    "Te 127.60",
    "I 126.90",
    "Xe 131.29",
    "Cs 132.91",
    "Ba 137.33",
    "La 138.91",
    "Ce 140.12",
    "Pr 140.91",
    "Nd 144.24",
    "Pm 144.91",
    "Sm 150.36",
    "Eu 151.96",
    "Gd 157.25",
    "Tb 158.92",
    "Dy 162.50",
    "Ho 164.93",
    "Er 167.26",
    "Tm 168.93",
    "Yb 173.05",
    "Lu 174.97",
    "Hf 178.49",
    "Ta 180.95",
    "W 183.84",
    "Re 186.21",
    "Os 190.23",
    "Ir 192.22",
    "Pt 195.08",
    "Au 196.97",
    "Hg 200.59",
    "Tl 204.38",
    "Pb 207.20",
    "Bi 208.98",
    "Po 208.98",
    "At 209.99",
    "Rn 222.02",
    "Fr 223.02",
    "Ra 226.03",
    "Ac 22.03",
    "Th 232.04",
    "Pa 231.04",
    "U 238.03",
    "Np 237.05",
    "Pu 244.06",
    "Am 243.06",
    "Cm 247.07",
    "Bk 247.07",
    "Cf 251.08",
    "Es 252.08",
    "Fm 257.10",
    "Md 258.10",
    "No 259.10",
    "Lr 262.11",
    "Rf 265.12",
    "Db 268.13",
    "Sg 271.13",
    "Bh 270.00",
    "Hs 277.15",
    "Mt 276.15",
    "Ds 281.16",
    "Rg 280.16",
    "Cn 285.17",
    "Uut 284.18",
    "Fl 289.19",
    "Uup 288.19",
    "Lv 293",
    "Uus 294",
    "Uuo 294",
};

int findElement(string c, int s) 
{
  string compare = c;
  int size = s;
  string elementName = "";
  //cout << "Find element" << endl;
  for (int i=0; i<(sizeof(elements)/sizeof(elements[0])); i++)
  {
    elementName = elements[i].substr(0,size);
    //cout << "elementName" << elementName << endl;
    if (elementName == compare)
    {
      //cout << "element name: " << elementName << endl;
      return i;
    }
  }
  return -1;
}

float getWeight (string c, int s)
{
  string compare = c;
  int size = s;
  string weight = "";
  float nWeight = 0;
  //cout << "Compare:" << compare << "test" << endl;
  int index = findElement(compare, size);
  //cout << "Index: " << index << endl;
  if (index != -1)
  {
    cout << "Element found: " << index+1 << endl;
    weight = elements[index].substr(1);
    for (int i=weight.length()-1; i>=0; i--)
    {
      if (isdigit(weight[i]) || weight[i]=='.')
      {
        continue;
      }
      else 
      {
        weight = weight.substr(i);
        break;
      }
    }
    nWeight = stof(weight);
    return nWeight;
  }
  else
  {
    cout << "Element not found" << endl;
  }
}

bool setClear()
{
  return false;
}

bool isLowercase(char let)
{
  if (let >= 'a' && let <= 'z')
  {
    return true;
  }
  return false;
}

bool isNumber(char let)
{
  if (let >= '0' && let <= '9')
  {
    return true;
  }
  return false;
}

int main()
{
  string formula = "";
  string compare = "";
  char let; 
  float weight = 0;
  int index = 0;
  int choice = 0;
  float elementTotal = 0;
  float endTotal = 0;
  vector<float> total;
  
  cout << "---Calculating the Molecular Weight of Compounds---" << endl << "1. Enter any compound" << endl << "2. You may use parentheses" << endl << "3. Case sensitive" << endl << "4. All numbers are computed as subscripts" << endl << "Ex: Cu3(PO4)2" << endl << "Enter a formula: ";
  cin >> formula;

  for (int i=0; i<formula.length(); i++)
    {
      let = formula[i];
      if (let >= 'A' && let <= 'Z')
        {
          choice = 1;
        }

      else if (let >= 'a' && let <= 'z')
      {
        choice = 2;
      }
      else if (let >= '0' && let <= '9')
      {
        choice = 3;
      }
      else if (let == '(')
      {
        choice = 4;
      }
      else if (let == ')')
      {
        choice = 5;
      }
      else
      {
        choice = 0;
      }
      switch (choice) {
        case 1:
          //cout << "Upper case" << endl;
          //cout << "elementTotal: " << elementTotal << endl;
          compare = formula[i];
          if (isLowercase(formula[i+1]))
          {
            //cout << "Next letter is lower case" << endl;
            break;
          }
          else if (isNumber(formula[i+1]))
          {
            //cout << "Next letter is a number" << endl;
            //cout << "Compare: " << compare << endl;
            //compare += formula[i];
            weight = getWeight(compare, 1);
            break;
          }
          else 
          {
            weight = getWeight(compare, 1);
            elementTotal = weight;
            //cout << "elementTotal: " << elementTotal << endl;
            total.push_back(elementTotal);
            //cout << "Total: " << total << endl;
            compare = "";
            elementTotal = 0;
            break;
          }
          break;
        case 2:
          //cout << "Lower case" << endl;
          compare += formula[i];
          weight = getWeight(compare, 2);
          if (isNumber(formula[i+1]))
          {
            //cout << "Next letter is a number" << endl;
            break;
          }
          else
          {
            elementTotal = weight;
            //cout << "elementTotal: " << elementTotal << endl;
            total.push_back(elementTotal);
            compare = "";
            elementTotal = 0;
            break;
            //cout << "Total: " << total << endl;
          }
        case 3:
          //cout << "Number" << endl;
          let = stoi(string(1, formula[i]));
          elementTotal = weight * let;
          //cout << "elementTotal: " << elementTotal << endl;
          total.push_back(elementTotal);
          //cout << "Total: " << total << endl;
          elementTotal = 0;
          endTotal = 0;
          compare = "";
          break;
        case 4:
          //cout << "(" << endl;
          total.push_back(0);
          break;
        case 5:
          //cout << ")" << endl;
          auto it = find(total.begin(), total.end(), 0);
          index = distance(total.begin(), it);
          for (int i=index; i<total.size(); i++)
          {
            endTotal += total[i];
            //cout << "End total: " << endTotal << endl;
          }
          for (int i=index; i<total.size(); i++)
          {
            total.pop_back();
            i--;
          }
          weight = endTotal;
          break;
     }
    }
    for (int i=0; i<total.size(); i++)
      {
        cout << "Total " << i+1 << ": " << total[i] << endl;
        endTotal += total[i];
      }
    cout << "Overall Total: " << endTotal << endl;

}