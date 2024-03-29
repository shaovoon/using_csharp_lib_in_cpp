# Consuming Your C# Library in MFC/C++ Project via C++/CLI

This article serves as a reference to using your .NET C# library in a native C++ project via C++/CLI in Visual Studio 2022. You can follow even if you are using earlier Visual Studio because the steps are mostly the same. It is initially written to answer a question on CodeProject's QnA. Your C++ project does not have to be MFC to follow the steps described here; it can be console or other types where you can ignore step 7 to add buttons to MFC dialog because it does not apply to your C++ project type. **Note:** This example does not cover hosting C# UI element in C++ UI; That is a complex topic.

For simplicity, we are going to use this simple C# class with `Add` and `AddList` methods in our C++ project.

```csharp
using System;

namespace CSharp
{
    public class CSharpMath
    {
        public int Add(int a, int b)
        {
            return a + b;
        }

        public int AddList(List<int> arr)
        {
            int sum = 0;
            foreach(int n in arr)
                sum += n;

            return sum;
        }
    }
}
```

**Step 1:** Open the MFC project's properties by right-clicking the project in the solution explorer and selecting "Properties".

![01_properties](img/01_properties.png)

**Step 2:** The Properties Pages dialog shows up. Enable the .NET CLR. The .NET Framework version has to be the same as your C# library.

![02_enable_clr](img/02_enable_clr.png)

**Step 3:** Add the reference to the C# library in the MFC project by right-clicking on the Reference node and selecting "Add Reference..."

![03_add_ref](img/03_add_ref.png)

Check on the C# project which you want to add reference.

![03_add_ref2](img/03_add_ref2.png)

**Step 4:** Next, we'll add a build dependency on the C# project so that whenever MFC/C++ is built, Visual Studio will build the C# project first.

![04_add_build_dep](img/04_add_build_dep.png)

Check the C# project for the build dependency.

![04_add_build_dep2](img/04_add_build_dep2.png)

**Step 5:** Open the MFC project's properties by right-clicking the project in the solution explorer and selecting "Properties". Click on the "Configuration Manager...". Make sure all the platform is the same. The C# project cannot be AnyCPU configuration: it has to be either x86 or x64, matching what the C++ project setting. If x86 or x64 do not exist, then you have to create them from AnyCPU settings.

![05_config_mgr](img/05_config_mgr.png)

**Step 6:** Close the Configuration Manager. Next, we add the `/AI` switch to the C++ compiler. `/AI` switch tells the C++ compiler where to find your C# dll. You must enter 4 different paths for Debug x86, Debug x64, Release x86 and Release x64. The paths can be relative. See below.

* /AI "..\\..\MFCwithCSharp\CSharpClass\bin\x86\Debug"
* /AI "..\\..\MFCwithCSharp\CSharpClass\bin\x64\Debug" 
* /AI "..\\..\MFCwithCSharp\CSharpClass\bin\x86\Release" 
* /AI "..\\..\MFCwithCSharp\CSharpClass\bin\x64\Release" 

![06_ai_switch](img/06_ai_switch.png)

**Step 7:** The last step is to add 2 buttons called "Add" and "Add List" to the MFC project. Double-click the button in the UI designer and a empty button handler will be created for you to call your C# `Add` or `AddList` methods.

![07_add_button](img/07_add_button.png)

**Step 8:** In the cpp where you will use your C# class, add the `using` keyword to import your C# dll. Amend the dll name according to yours.

```Cpp
#using "CSharpClass.dll"
```

In our first button handler, add these code to call the C# class's `Add()`. Make sure the C# class type ends with a hat(^) and use `gcnew` to instantiate your C# class (Do not use `new` keyword because it is reserved for instantiating native C++ objects on the heap). It shows the addition result in a message box.

```Cpp
void CMFCwithCSharpDlg::OnBnClickedBtnAdd()
{
    CSharp::CSharpMath^ mathClass = gcnew CSharp::CSharpMath();
    int result = mathClass->Add(2, 6);

    char buf[200];
    sprintf_s(buf, "Add result: %d", result);
    MessageBoxA(GetSafeHwnd(), buf, "Add", MB_OK);
}
```

You can use .NET Base Class Library (BCL) such as `List` class. Replace the dots with `::` in the namespace. Remember to add another button to the MFC dialog to call `AddList()` and add the code below to the function.

```Cpp
void CMFCwithCSharpDlg::OnBnClickedBtnAddList()
{
    CSharp::CSharpMath^ mathClass = gcnew CSharp::CSharpMath();

    System::Collections::Generic::List<int>^ myList = gcnew System::Collections::Generic::List<int>();

    myList->Add(1);
    myList->Add(2);
    myList->Add(3);

    int result = mathClass->AddList(myList);

    char buf[200];
    sprintf_s(buf, "Add List result: %d", result);
    MessageBoxA(GetSafeHwnd(), buf, "Add List", MB_OK);
}
```

Build your C++ project and the C# project automatically builds first because of the build dependency set in step 4. Click the "Add" or "Add List" button. Make sure it does not crash and the result is correct. If you encounter the error of "C# dll cannot be found" on customer computer, you need to copy the C# dll to the C++ executable folder.

That's all for the example. Hopefully, you can use your C# library in your C++ project. Your next step is to master C++/CLI.
