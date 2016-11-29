#pragma once
#ifndef HELPER_H
#define HELPER_H
#include <ctime>
#include <string>
#include <fstream>
#include <sstream> 

namespace Helper
{
	template <class T >
	std::string  ToString (const T &);  //function declaration  

	//Creating a structure for this scenario  
	struct DateTime
	{
		int D, m, y, H, M, S;
		DateTime ()  //THis is a constructor 
		{
			time_t ms;
			time (&ms);
			tm *info = localtime (&ms);  // add struct before tm or not , it makes no sense . 
			D = info->tm_mday;
			m = info->tm_mon + 1;
			y = info->tm_year + 1900;
			H = info->tm_hour;
			M = info->tm_min;
			S = info->tm_sec;
		}

		DateTime (int D, int m, int y, int H, int M, int S) :D (D), m (m), y (y), H (H), M (M), S (S) {}
		DateTime (int D, int m, int y) :D (D), m (m), y (y), H (0), M (0), S (0) {}

		DateTime Now () const
		{
			return DateTime ();
		}

		std::string  GetDateString () const
		{
			return std::string (D < 10 ? "0" : " ") + ToString (D) + std::string (m < 10 ? ".0" : ".") + ToString (m) + "." + ToString (y);
		}

		std::string GetTimeString (const std::string &sep = ":")
		{
			return std::string (H < 10 ? "0" : "") + ToString (H) + std::string (M < 10 ? "0" : "") + ToString (M) + std::string (M < 10 ? "0" : "")
				+ ToString (S);
		}

		std::string GetDateTimeString (const std::string &sep = ":")
		{
			return GetDateString () + GetTimeString (sep);
		}



	};

	//Creating the ToString definition in this namepsace ; 
	template <class T >
	std::string  ToString (const T &e)
	{
		std::ostringstream s;
		s << e;
		return  s.str ();
	}

	void WriteAppLog (const std::string &s)
	{
		std::ofstream file ("AppLog.txt", std::ios::app);
		file << " [" << Helper::DateTime().GetDateTimeString () << "]" << "\n" << std::endl;  //Namespace :: StructConstructor.memberfunction 

	}

}



#endif // !HELPER_H
