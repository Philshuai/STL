#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

template<class T>
String<T>::String() :pstart(nullptr), length(0)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{

	}
	else if(strcmp(typeid(T).name(), "wchar_t") == 0)
	{

	}
	else
	{
		cout << "类型不匹配" << endl;
	}
}
template<class T>
String<T>::String(const T *p)
{
	//严格注意类型，const char *与char *严格区分
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		this->length = strlen(reinterpret_cast<const char *>(p))+1;
		this->pstart = new T[this->length];
		strcpy(reinterpret_cast<char *>(this->pstart), reinterpret_cast<const char *>(p));//初始化
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		this->length = wcslen(reinterpret_cast<const wchar_t *>(p))+1;
		this->pstart = new T[this->length];
		wcscpy(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<const wchar_t *>(p));//初始化
	}
	else
	{
		cout << "类型不匹配" << endl;
	}

}

template<class T>
String<T>::~String()
{ 
	//RAAI 运行即释放
	if (this->pstart != nullptr)
	{
		delete[] this->pstart;
	}

}

template<class T>
String<T>::String(const String &str)
{
	pstart = nullptr;
	if (this->pstart != nullptr)
	{
		delete[] this->pstart;
	}
	this->length = 0;

	this->length = str.length;
	this->pstart = new T[this->length]; 

	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char *>(this->pstart), reinterpret_cast< const char *>(str.pstart));
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<const wchar_t *>(str.pstart));
	}
	else
	{
		cout << "类型不匹配" << endl;
	}

}
template<class T>
void String<T>::operator=(const String &str)
{
	pstart = nullptr;
	if (this->pstart != nullptr)
	{
		delete[] this->pstart;
	}
	this->length = 0;

	this->length = str.length;
	this->pstart = new T[this->length];

	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char *>(this->pstart), reinterpret_cast< const char *>(str.pstart));
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<const wchar_t *>(str.pstart));
	}
	else
	{
		cout << "类型不匹配" << endl;
	}

}
template<class T>
T String<T>::operator[](int id) const 
{
	if (id < 0 || id >= this->length)
	{
		throw erroroutofrange();
	}
	return this->pstart[id];
}
template<class T>
T &String<T>::operator[](int id)
{
	if (id < 0 || id >= this->length)
	{
		throw erroroutofrange();//抛出异常
	}
	return this->pstart[id];
}



template<class T>
void String<T>::show()
{

	if (strcmp(typeid(T).name(), "char") == 0)
	{
		cout <<reinterpret_cast<const char *> (this->pstart) << endl;
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcout << reinterpret_cast<const wchar_t *> (this->pstart) << endl;
	}
	else
	{
		cout << "类型不匹配" << endl;
	}

}

template<class T>
void String<T>::operator +=(const String &str)
{

	this->length += (str.length-1);//长度
	T *ptemp = new T [this->length];

	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char *>(ptemp), reinterpret_cast< const char *>(this->pstart));
		strcat(reinterpret_cast<char *>(ptemp), reinterpret_cast<const char *>(str.pstart));

		delete[] this->pstart;
		this->pstart = ptemp;

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t *>(ptemp), reinterpret_cast<const wchar_t *>(this->pstart));
		wcscat(reinterpret_cast<wchar_t *>(ptemp), reinterpret_cast<const wchar_t *>(str.pstart));

		delete[] this->pstart;
		this->pstart = ptemp;
		  
	}
	else
	{
		cout << "类型不匹配" << endl;
	}

}

template<class T>
String<T> String<T>::operator +(String &str)
{

	String<T> stemp;
	stemp.length = this->length + str.length;
	stemp.pstart = new T[stemp.length];

	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char *>(stemp.pstart), reinterpret_cast< const char *>(this->pstart));
		strcat(reinterpret_cast<char *>(stemp.pstart), reinterpret_cast<const char *>(str.pstart));

	

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t *>(stemp.pstart), reinterpret_cast<const wchar_t *>(this->pstart));
		wcscat(reinterpret_cast<wchar_t *>(stemp.pstart), reinterpret_cast<const wchar_t *>(str.pstart));
	}
	else
	{
		cout << "类型不匹配" << endl;
	}

	return stemp;

}
template<class T>
T * String<T>::getdata()
{
	return this->pstart;

}
template<class T>
bool String<T>::operator ==(const String &str)
{

	if (strcmp(typeid(T).name(), "char") == 0)
	{
		return (strcmp(reinterpret_cast<char *>(this->pstart), reinterpret_cast<char *>(str.pstart)) == 0);
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{

		return (wcscmp(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<wchar_t *>(str.pstart)) == 0);
	}
	else
	{
		cout << "类型不匹配" << endl;
	}

}


template<class T>
bool String<T>:: operator <=(const String &str)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		return (strcmp(reinterpret_cast<char *>(this->pstart), reinterpret_cast<char *>(str.pstart)) <= 0);
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{

		return (wcscmp(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<wchar_t *>(str.pstart)) <= 0);
	}
	else
	{
		cout << "类型不匹配" << endl;
	}
}

template<class T>
bool String<T>::operator >=(const String &str)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		return (strcmp(reinterpret_cast<char *>(this->pstart), reinterpret_cast<char *>(str.pstart)) >= 0);
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{

		return (wcscmp(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<wchar_t *>(str.pstart)) >= 0);
	}
	else
	{
		cout << "类型不匹配" << endl;
	}
}

template<class T>
bool String<T>:: operator <(const String &str)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		return (strcmp(reinterpret_cast<char *>(this->pstart), reinterpret_cast<char *>(str.pstart)) < 0);
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{

		return (wcscmp(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<wchar_t *>(str.pstart)) < 0);
	}
	else
	{
		cout << "类型不匹配" << endl;
	}
}
template<class T>
bool String<T>:: operator >(const String &str)
{


	if (strcmp(typeid(T).name(), "char") == 0)
	{
		return (strcmp(reinterpret_cast<const char *>(this->pstart), reinterpret_cast<const char *>(str.pstart)) > 0);
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		return (wcscmp(reinterpret_cast<const wchar_t *>(this->pstart), reinterpret_cast<const wchar_t *>(str.pstart)) > 0);
		return 0;
	}
	else
	{
		cout << "类型不匹配" << endl;
	}
}

template<class T>
bool String<T>::operator !=(const String &str)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		return (strcmp(reinterpret_cast<char *>(this->pstart), reinterpret_cast<char *>(str.pstart)) != 0);
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{

		return (wcscmp(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<wchar_t *>(str.pstart)) != 0);
	}
	else
	{
		cout << "类型不匹配" << endl;
	}
}
template<class T>
T * String<T>::operator*()
{


	return this->pstart;

}

template<class T>
String<T> *String<T>::operator ->()
{
	return this;
}

template<class T>
String<T> *String<T>::operator ->*(int i)
{

	return this;
} 
template<class T>
int String<T>::getlength()
{
	return this->length;
}


template<class T>
void String<T>::replacefirst(const String<T> &oldstr, const String<T> &newstr)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		//reinterpret_cast<char *>
		char *p = strstr(reinterpret_cast<char *>(this->pstart), reinterpret_cast<char *>(oldstr.pstart));
		if (p != nullptr)
		{
			int oldlength = strlen(reinterpret_cast<char *>(oldstr.pstart));
			int newlength = strlen(reinterpret_cast<char *>(newstr.pstart));

			if (oldlength == newlength)
			{
				memcpy(p, newstr.pstart,(newstr.length-1)*sizeof(T));

			}
			else if (oldlength > newlength)
			{
				memcpy(p, newstr.pstart, newstr.length - 1);
				int mlength = oldlength - newlength;
				int movelength = this->length - oldlength - (p - reinterpret_cast<char *>(this->pstart));//要移动的长度
				for (size_t i=0; i < movelength; i++)//拷贝
				{
					(p + newlength)[i] = (p + newlength)[i + mlength];
				}
				this->length += newlength - oldlength;
			}
			else
			{
				T *ptemp = new T[this->length + newlength - oldlength];
				memcpy(ptemp, this->pstart, sizeof(T)*(p - reinterpret_cast<char *>(this->pstart)));
				memcpy(ptemp + sizeof(T)*(p - reinterpret_cast<char *>(this->pstart)), newstr.pstart, newlength);
				memcpy(ptemp + sizeof(T)*(p - reinterpret_cast<char *>(this->pstart)) + newlength, p + oldlength, this->length - oldlength - (sizeof(T)*(p - reinterpret_cast<char *>(this->pstart))));
				delete[] this->pstart;

				this->pstart = ptemp;
				this->length += newlength - oldlength;
			}

		}

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wchar_t *p = wcsstr(reinterpret_cast<wchar_t *>(this->pstart), reinterpret_cast<wchar_t *>(oldstr.pstart));
		if (p != nullptr)
		{
			int oldlength = wcslen(reinterpret_cast<wchar_t *>(oldstr.pstart));
			int newlength = wcslen(reinterpret_cast<wchar_t *>(newstr.pstart));//计算得到的是宽字符个数不是字节数

			if (oldlength == newlength)
			{
				memcpy(p, newstr.pstart, (newstr.length - 1)*sizeof(T));

			}
			else if (oldlength > newlength)
			{
				//cout << newlength << endl;
				memcpy(p, newstr.pstart, sizeof(T)*newlength);
				//cout << newstr.length << endl;
				int mlength = oldlength - newlength;
				int movelength = this->length - oldlength - (p - reinterpret_cast<wchar_t*>(this->pstart));//要移动长度
				//cout << movelength << endl;

				for (size_t i = 0; i < movelength; i++)//拷贝
				{
					(p + newlength)[i] = (p + newlength)[i + mlength];
				}

				this->length += (newlength - oldlength);
			}
			else
			{
				cout << newlength << endl;
				T *ptemp = new T[this->length + newlength - oldlength];
				memcpy(ptemp, this->pstart, sizeof(T)*(p - reinterpret_cast<wchar_t *>(this->pstart)));
				memcpy(ptemp + (p - reinterpret_cast<wchar_t*>(this->pstart)), newstr.pstart, sizeof(T)*newlength);
				memcpy(ptemp + (p - reinterpret_cast<wchar_t*>(this->pstart) + newlength), p + oldlength, sizeof(T)*(this->length - oldlength - (p - reinterpret_cast<wchar_t*>(this->pstart)) + 1));
				delete[]this->pstart;
				this->pstart = ptemp;
				this->length += (newlength - oldlength);
			}
		}
	}
	else
	{
		cout << "类型不匹配" << endl;
	}
}