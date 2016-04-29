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

#ifndef __WRAPPER_H__
#define __WRAPPER_H__

#include <Arduino.h>

class Wrapper {

	public:

		virtual int type(); //funzione che restituisce il tipo di wrapper
		
		static const int STRING = 0; //String
		static const int DOUBLE = 1; //Long
		static const int BOOLEAN = 2; //bool
		static const int LONG = 3; //long
		static const int JDATA = 4; //jdata
		
};

class BooleanWrapper : public Wrapper {

	public:

		BooleanWrapper(int value); //costruttore per riempire l'oggetto

		int type(); //funzione che restituisce il tipo di wrapper

		int getBoolean(); //funzione per estrarre il valore

	private:

		int value; //contenitore del valore

};

class DoubleWrapper : public Wrapper {

	public:

		DoubleWrapper(double value); //costruttore per riempire l'oggetto
		
		DoubleWrapper(String value);

		int type(); //funzione che restituisce il tipo di wrapper

		double getDouble(); //funzione per estrarre il valore
		
		String getString(); //use default precision
		String getString(int precision); //use default precision

	private:

		double value; //contenitore del valore

};

class LongWrapper : public Wrapper {

	public:

		LongWrapper(long value); //costruttore per riempire l'oggetto
		
		LongWrapper(String value);

		int type(); //funzione che restituisce il tipo di wrapper

		long getLong(); //funzione per estrarre il valore

	private:

		long value; //contenitore del valore

};

class StringWrapper : public Wrapper {

	public:

		StringWrapper(String value); //costruttore per riempire l'oggetto

		int type(); //funzione che restituisce il tipo di wrapper

		String getString(); //funzione per estrarre il valore

	private:

		String value; //contenitore del valore

};

#endif
