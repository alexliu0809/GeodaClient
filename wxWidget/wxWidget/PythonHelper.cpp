//
//  PythonHelper.cpp
//  wxWidget
//
//  Created by Enze on 4/27/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#include "PythonHelper.h"

/** Report Errors */
void ReportError(char *msg)
{
    printf("Error: %s\n",msg);
}

/** set the environment. workingspace is where the py files are located */
void InitializePython()
{
    Py_Initialize(); //Initialize Python Interpreter.
}
int InitializePythonEnv(char *workingspace)
{
    PyRun_SimpleString("import sys"); //run a simple python code
    
    char *cmd = (char *)malloc((strlen(workingspace)+50)*sizeof(char));
    memset(cmd,0,sizeof((strlen(workingspace)+50)*sizeof(char)));
    strcat(cmd, "sys.path.insert(0,'");
    strcat(cmd,workingspace);
    strcat(cmd,"')");
    //cmd = sys.path.insert(0,path/to/the/pyfiles) so that the file python files can be found in certain path
    
    PyRun_SimpleString(cmd);
    return 1;
}

/** disbale the interpreter */
void FinalizePython()
{
    Py_Finalize();
}

/**
 Run a entire .py file
 
 envAddress: System path. Use "." if not need to set specifically.
 fileAddress: Address to the python file. Include .py. DO NOT Use "_" for filename
 */
int Python_RunFile(char *envAddress,char *fileAddress)
{
    
    
    if (InitializePythonEnv(envAddress) == 0) //init failed
    {
        ReportError("initializing environment failed");
        FinalizePython();
        return 0;
    }
    
    FILE* pythonFilePtr = nullptr;
    pythonFilePtr = fopen(fileAddress, "r");
    
    if (pythonFilePtr == nullptr) //open failed
    {
        ReportError("Open python file failed");
        FinalizePython();
        return 0;
    }
    
    PyRun_SimpleFile(pythonFilePtr, fileAddress); //execute the py file.
    return 1;
}

/**
 Run a module from a python file.
 
 envAddress: System path (where the py files are located). Use "." if not need to set specifically.
 fileAddress: Address to the python file. DONT NOT Add .py after the name
 moduleName: User defined args.
 pArgs: Argument sets
 pResult: should point to the return value
 
 */
int Python_RunModule(char *envAddress,char *fileAddress, char *moduleName,PyObject *pArgs, PyObject **pResult)
{
    
    PyObject *pName = nullptr,*pModule=nullptr,*pFunc=nullptr;
    
    if (InitializePythonEnv(envAddress) == 0)
    {
        ReportError("initializing environment failed");
        FinalizePython();
        return 0;
    }
    
    pName = PyString_FromString(fileAddress);
    if (pName == nullptr)
    {
        ReportError("Translate File Name Failed");
        FinalizePython();
        return 0;
    }
    
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if (pModule == nullptr)
    {
        ReportError("Import Module Failed");
        FinalizePython();
        return 0;
    }
    
    pFunc = PyObject_GetAttrString(pModule, moduleName);
    Py_DECREF(pModule);
    if (!(pFunc && PyCallable_Check(pFunc)))
    {
        ReportError("Function not callable");
        FinalizePython();
        return 0;
    }
    
    PyObject *tempResult = PyObject_CallObject(pFunc, pArgs);
    Py_DECREF(pFunc);
    if (tempResult != nullptr)
    {
        *pResult = tempResult;
        //Result returned correctly
        //printf("Result of call: %ld\n", PyInt_AsLong(tempResult));
    }
    else
    {
        ReportError("Call failed");
        Py_DECREF(tempResult);
        FinalizePython();
        return 0;
    }
    Py_DECREF(tempResult);
    return 1;
}


/************************* Operations on argument pointer  *************************/
/** Set an argument pointer with value pVal at position i*/
void Python_Set_One_Arg(PyObject *pArgs, int position, PyObject *pVal)
{
    PyTuple_SetItem(pArgs, position, pVal);
}

/** Initialize a pointer with n arguments*/
PyObject* Python_Init_Arg_Pointer(int numArgs)
{
    return PyTuple_New(numArgs);
}


/************************* Create certain argument type  *************************/
/** Create an integer argument */
PyObject* Python_Get_Int_From_Int(int num)
{
    return Py_BuildValue("i", num);
}

/** Create an Float argument */
PyObject* Python_Get_Float_From_Float(float num)
{
    return Py_BuildValue("f", num);
}

/** Create an String argument */
PyObject* Python_Get_String_From_String(char *str)
{
    return Py_BuildValue("s", str);
}

/** Create an List argument */
PyObject* Python_Create_List(int numElements)
{
    return PyList_New(numElements);
}
/** Add Element to List */
void Python_Add_List_Element(PyObject*pList, int position, PyObject* element)
{
    PyList_SetItem(pList,position,element);
}
/** Append Element to List */
void Python_Append_List_Element(PyObject*pList, PyObject* element)
{
    PyList_Append(pList,element);
}




int RunPython()
{
    
    //InitializePython();
    
    PyObject *pValue=nullptr,*pArgs=nullptr,*pValue1,*pValue2,*pValue3,*pValue4;
    PyObject *pResult,*pList1,*pList2;
    
    
    
    
    
    printf("Test2:Test RunModule Function without Args\n");
    Python_RunModule("/Users/Enze/Desktop/", "noArgMain", "main", nullptr,&pResult);
    //printf("\n\n");
    
    
    //You need to finalize Python somewhere
    //FinalizePython();
    return 0;
}

