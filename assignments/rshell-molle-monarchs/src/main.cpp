#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <deque>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

bool filestats(const char* filename, string flag)
{
  struct stat buf; 
  struct stat sb;

  if (flag == "-e")
  {
    return (stat(filename, &buf) == 0);
  }
  else if (flag == "-f")
  {
    if (stat(filename, &sb) == 0)
    {
      if (S_ISREG(sb.st_mode) != 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  else if (flag == "-d") 
  {
    if (stat(filename, &sb) == 0)
    {
      if (S_ISDIR(sb.st_mode) != 0)
      {
        return true;
      }
      else 
      {
        return false;
      }
    }
  }
  else
  {
    return false;
  }
  return false;
}

//Handles fork(), exit, and test();
int run(char** argv)
{
 
  if (strncmp(argv[0], "exit", 4) == 0) 
  {
    exit(0);
  }
  else if (strncmp(argv[0], "test", 4) == 0)
  {
    if (strncmp(argv[1], "-e", 2) == 0)
    {
      if (filestats(argv[2], "-e"))
      {
        cout << "(True)" << endl;
      }
      else 
      {
        cout << "(False)" << endl;
      }
    }
    else if (strncmp(argv[1], "-f", 2) == 0)
    {
      if (filestats(argv[2], "-f"))
      {
        cout << "(True)" << endl;
      }
      else
      {
        cout << "(False)" << endl;
      }
    }
   else if (strncmp(argv[1], "-d", 2) == 0)
   {
     if (filestats(argv[2], "-d"))
     {
       cout << "(True)" << endl;
     }
     else
     {
       cout << "(False)" << endl;
     }
   }
   else
   {
     if (filestats(argv[1], "-e"))
     {
       cout << "(True)" << endl;
     }
     else
     {
       cout << "(False)" << endl;
     }
   }
   

 }
  else if (strncmp(argv[0], "[", 1) == 0)
  {
    if (strncmp(argv[4], "]", 1) != 0)
    {
      cout << "Missing closing bracket." << endl;
    }
    else if (strncmp(argv[1], "-e", 2) == 0)
    {
      if (filestats(argv[3], "-e"))
      {
        cout << "(True)" << endl;
      }
      else
      {
        cout << "(False)" << endl;
      }
    }
    else if (strncmp(argv[1], "-f", 2) == 0)
    {
      if (filestats(argv[3], "-f"))
      {
        cout << "(True)" << endl;
      }
      else
      {
        cout << "(False)" << endl;
      }
    }
    else if (strncmp(argv[1], "-d", 2) == 0)
    {
      if (filestats(argv[3], "-d"))
      {
        cout << "(True)" << endl;
      }
      else
      {
        cout << "(False)" << endl;
      }
    }
    else
    {
     if (filestats(argv[2], "-e"))
     {
       cout << "(True)" << endl;
     }
     else
     {
       cout << "(False)" << endl;
     }
    } 

  }
  
  int i, j;
  char* inname = 0;
  char* outname = 0;
  char* appname = 0;
  for (i = 0; argv[i] != 0; i++)
  {
    if (strcmp(argv[i], "<") == 0)
    {
      inname = argv[i+1];
      for (j = i; argv[j+2] != 0; j++)
      {
        argv[j] = argv[j+2];
      }
      argv[j] = 0;
      i--;
    }
    else if (strcmp(argv[i], ">") == 0)
    {
      outname = argv[i+1];
      for (j = i; argv[j+2] != 0; j++)
      {
        argv[j] = argv[j+2];
      }
      argv[j] = 0;
      i--;
    }
    else if (strcmp(argv[i], ">>") == 0)
    {
      appname = argv[i+1];
      for (j = i; argv[j+2] != 0; j++)
      {
        argv[j] = argv[j+2];
      }
      argv[j] = 0;
      i--;
    }
  }
  

  int pid = fork();
  if (pid == -1)
  { 
    perror("fork");
    return 0;
  }
  else if (pid == 0)
  {
    if (inname != 0)
    {
      int infd = open(inname, O_RDONLY);
      dup2(infd, 0);
    }

    if (outname != 0)
    {
      int outfd = open(outname, O_WRONLY | O_CREAT, 0666);
      dup2(outfd, 1);
    }

    if (appname != 0)
    {
      int appfd = open(appname, O_WRONLY | O_CREAT | O_APPEND, 0666);
      dup2(appfd, 1);
    }

    execvp(argv[0], argv);
    perror(argv[0]);
    exit(EXIT_FAILURE);
    return 0;
  }
  else
  { 
    int status;
    if (waitpid(pid, &status, 0) == -1) 
    {
      perror("waitpid");
      return 0;
    }
    return status == 0;
  }
}


typedef int (*connector)(int,char**);


int cand(int left, char** right)
{
  return left && run(right);
}

int cor(int left, char** right) 
{
  return left || run(right);
}
//Executes commands based using tokenization
int execute(char* command)
{
  bool status = 1;
  connector conn = cand;
  vector<char*> arguments;

  
  char* arg = strtok(command, " ");
  while (arg != 0) 
  {
    if (strncmp(arg, "&&", 2) == 0)
    {
      arguments.push_back(0);
      status = conn(status, arguments.data());
      arguments.clear();
      conn = cand;
    }
    else if (strncmp(arg, "||", 2) == 0)
    {
      arguments.push_back(0);
      status = conn(status, arguments.data());
      arguments.clear();
      conn = cor;
    }
    else
    {
      arguments.push_back(arg);
    }
    arg = strtok(NULL, " ");
  }
  arguments.push_back(0);
  status = conn(status, arguments.data());
  return status;
}

// Help to take apart the parentheses 
char* deparenthesize(char* input)
{
  bool parens = false;
  for (unsigned int i = 0; i != strlen(input); i++)
  {
    if (input[i] == '(')
    {
      parens = true;
      break;
    }
  }
  
  if (parens == true)
  {
    string output; 
    for (unsigned int i = 0; i != strlen(input); i++)
    {
      if ((input[i] == '(') || (input[i] == ')'))
      {
        if (i != strlen(input) - 1)
        { 
          i++;
          if ((input[i] != '(') && (input[i] != ')'))
          {
            output.push_back(input[i]);
          }
        }
      }
      else
      {
        output.push_back(input[i]);
      }
    }
    cout << output << endl;
    return (char*)output.c_str();
  }
  else
  {
    return input;
  }
}


//Groups commands within parentheses
deque<string> commandqueue(char* statement)
{
  vector<string> output;
  deque<string> output1;
  string store;  
  unsigned int j;

  for (unsigned int i = 0; i != strlen(statement); i++)
  {
     if (statement[i] == '(')
     {
       if (!store.empty())
       {
         output1.push_back(store); 
         store.clear();
       } 

       j = i;

       while (statement[j] != ')')
       {
         store.push_back(statement[j]);
         j++;
       }
       store.push_back(')');

       i = j;
       
       output1.push_back(store);
       store.clear();
     }   
     else if (statement[i] == '&')
     {
       output1.push_back(store);
       store.clear();
       store.push_back(statement[i]);
       store.push_back(statement[i]);
       i++;
       i++;
     } 
     else
     {
       store.push_back(statement[i]);
     }
  }

/* for (unsigned k = 0; k < output1.size(); k++)
 {
   cout << output1.at(k) << " at " << k << " "; 
 }
 cout << endl;*/
  
  return output1;
}


//checks for parentheses
bool parencheck (char* input)
{
  bool check = false;
  for (unsigned int i = 0; i != strlen(input); i++)
  {
    if (input[i] == '(')
    {
      check = true;
      break;
    }
  }
  return check;
}

//Tokenizes based on semicolon
void semitok(char* str)
{
  char* rest;
  char* statement = strtok_r(str, ";", &rest);
  int executecorrect; 
  deque<string> queuestatement = commandqueue(statement);
  bool parens = false;
 
  parens = parencheck(statement);
  
  if (parens)
  {
    while (queuestatement.size() != 0)
    {
      if ((queuestatement.at(0) != " || ") && (queuestatement.at(0) != " && ") && (queuestatement.at(0) != "&&") && (queuestatement.at(0) != "||"))
      {  
        string current = queuestatement.at(0);
        char* statement2 = deparenthesize((char*)current.c_str());
       
        while (statement2 != 0)
        {
          executecorrect  = execute(statement2);
          statement2 = strtok_r(NULL, ";", &rest);
        }
        queuestatement.pop_front();
      }
      else if ((queuestatement.at(0) == " || ") || (queuestatement.at(0) == "||"))
      {
        if (executecorrect == 1)
        {
          queuestatement.pop_front();
          queuestatement.pop_front();
        }
        else
        {
          queuestatement.pop_front();
        }
      }
      else if ((queuestatement.at(0) == "&&") || (queuestatement.at(0) == " && "))
      {
        if (executecorrect == 1)
        {
          queuestatement.pop_front();
        }
        else
        {
          queuestatement.pop_front();
          queuestatement.pop_front();
        }
      }
     }
  }
  else
  {
    while(statement != 0)
    {
      execute(statement);
      statement = strtok_r(NULL, ";", &rest);
    }
  }
}
// main function
int main(int argc, char** argv)
{
  string input;

  // take input
  while (!cin.eof()) 
  {
    cout << "$ ";
    getline(cin, input);
    input = input.substr(0,input.find("#",0));
    semitok((char*)input.c_str());
  }
  
  return 0;
}
