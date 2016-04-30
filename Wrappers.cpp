/*
   Copyright 2016 Alessandro Pasqualini

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   
   @author         Alessandro Pasqualini <alessandro.pasqualini.1105@gmail.com>
   @url            https://github.com/alessandro1105
*/

#include <Arduino.h>
#include "Wrappers.h"


//BOOLEAN WRAPPER
BooleanWrapper::BooleanWrapper(uint8_t value) { //construttore/incapsulatore

	if (value > 0) {
		_value = 1;
	} else {
		_value = 0;
	}

}

int BooleanWrapper::getBoolean() { //restituisce il valore memorizzato

	return _value;

}

uint8_t BooleanWrapper::type() { //zrestituisco il tipo di wrapper

	return WR_BOOLEAN;
	
}

//DOUBLE WRAPPER
DoubleWrapper::DoubleWrapper(double value) { //construttore/incapsulatore

	_value = value;

}

DoubleWrapper::DoubleWrapper(String value) { //construttore/incapsulatore

	//creo un buffer per contenere la stringa
	char buffer[value.length() +1];
		
	//converto la stringa in un array di caratteri
	value.toCharArray(buffer, sizeof(buffer));
		
	//converto il buffer in float
	_value = atof(buffer);

}

double DoubleWrapper::getDouble() { //restituisce il valore memorizzato

	return _value;

}

String DoubleWrapper::getString(int decimal) { // restituisce il double convertito in stringa
	
	long integerPart;
	double decimalPart;
	
	int moltiplier = 1;
	
	if (decimal > 5) {
		decimal = 5;
	}
	
	integerPart = floor(_value);
	
	decimalPart = (_value - integerPart);
	

	
	while (((int) decimalPart) - decimalPart < 0) {		
		
		if (moltiplier > (decimal)) { //verifico l'arrotondamento con una cifra dopo di quelle richieste
		
			if (((decimalPart - floor(decimalPart)) * 10) >= 5) { //arrotondamento necessario per eccesso
				
				String decimalPartString = String((long) decimalPart); //trasformo in stringa la parte decimale
				
				int size = decimalPartString.length(); //ricavo la lunghezza
				
				decimalPart += 1; //sommo 1 perchè devo arrotondare
				
				decimalPartString = String((long) decimalPart); //ritrasformo in stringa il numero arrotondato
				
				if (size != decimalPartString.length()) { //overlow (tutti erano a 9)
				
					integerPart += 1; //aggiungo 1 alla parte intera
					
					decimalPart = 0; //azzero la parte decimale
				
				}
				
			}
			
			break;
		}
		
		decimalPart *= 10;
		moltiplier++;
		
	}

	return String(integerPart) + "." + String((long) decimalPart);

}

String DoubleWrapper::getString() { // restituisce il double convertito in stringa

	return getString(5); //ritorno il numero in stringa con 5 decimali
}

uint8_t DoubleWrapper::type() { //zrestituisco il tipo di wrapper

	return WR_DOUBLE;

}


//LONG WRAPPER
LongWrapper::LongWrapper(long value) { //construttore/incapsulatore

	_value = value;

}

LongWrapper::LongWrapper(String value) { //construttore/incapsulatore

	char buffer[value.length() +1];
	
	value.toCharArray(buffer, sizeof(buffer));
	

	_value = atol(buffer);

}

long LongWrapper::getLong() { //restituisce il valore memorizzato

	return _value;

}

uint8_t LongWrapper::type() { //zrestituisco il tipo di wrapper

	return WR_LONG;

}


//STRING WRAPPER
StringWrapper::StringWrapper(String value) { //construttore/incapsulatore

	_value = value;

}

String StringWrapper::getString() { //restituisce il valore memorizzato

	return _value;

}

uint8_t StringWrapper::type() { //zrestituisco il tipo di wrapper

	return WR_STRING;

}