# Example of Using C# Library in MFC/C++ Project

For simplicity, we are going to use this C# class below in our C++ project.

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
    }
}
```

Opens the MFC project's properties by the right-clicking the project in the solution explorer and select "Properties".

![01_properties](img/01_properties.png)

The Properties Pages dialog shows up. Enable the .NET CLR. The .NET Framework version has to be the same as your C# library.

![02_enable_clr](img/02_enable_clr.png)

Add the reference to the C# library in the MFC project by right-clicking on the Reference node and select "Add Reference..."

![03_add_ref](img/03_add_ref.png)

Check on the C# project which you want to add reference.

![03_add_ref2](img/03_add_ref2.png)

Next, we'll add a build dependency on the C# project so that whenever MFC/C++ is built, Visual Studio will build the C# project first.

![04_add_build_dep](img/04_add_build_dep.png)

Check the C# project for the build dependency.

![04_add_build_dep2](img/04_add_build_dep2.png)

Opens the MFC project's properties by the right-clicking the project in the solution explorer and select "Properties". Click on the "Configuration Manager...". Make sure all the platform is the same. The C# project cannot be AnyCPU configuration: it has to be either x86 or x64, matching what the C++ project setting. If x86 or x64 does not exist, then you have to create them from AnyCPU settings.

![05_config_mgr](img/05_config_mgr.png)

Close the Configuration Manager after all the platform. Next, we add the /AI switch to the C++ compiler. /AI switch tells the C++ compiler where to find your C# dll. Do not use my path here because it will be certainly different from yours. You have to enter 4 different paths for Debug x86, Debug x64, Release x86 and release x64.

![06_ai_switch](img/06_ai_switch.png)

The last step is to add a button to the MFC project. And give the button a caption and meaningful name and double click the button in the UI designer and a empty button handler will be created for you to call your C# Add function.

![07_add_button](img/07_add_button.png)

In the cpp where you're going to use the C# class, add the using keyword to import your C# dll. Amend the dll name according to what you have.

```Cpp
#using "CSharpClass.dll"
```

In our button handler, add these code to call the C# class's Add(). Make sure the C# class type ends with a hat(^) and use gcnew to instiatante your C# class (Do not use new keyword because it is reserved for instiatanting native C++ objects on the heap). It shows the addition result in a message box.

```Cpp
void CMFCwithCSharpDlg::OnBnClickedBtnAdd()
{
    CSharp::CSharpMath^ mathClass = gcnew CSharp::CSharpMath();
    int result = mathClass->Add(2, 6);

    char buf[200];
    sprintf_s(buf, "result: %d", result);
    MessageBoxA(GetSafeHwnd(), buf, "Message", MB_OK);
}
```

Build your C++ project and the C# project automatically builds first because of the build dependency set earlier. Click the Add button. Make sure it does not crash and the result is correct.

That's all for the example. Hopefully you can use your C# library in your C++ project. Next step is to learn C++/CLI.
