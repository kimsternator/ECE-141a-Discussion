# CLion Setup
This is the step-by-step instructions of how to set up your CLion environment for ECE 17.

This setup will be done for the Windows OS, but the steps should remain relatively the same for other operating systems.
## Installation
**Note**: If you already have a JetBrains student pack, navigate to the CLion page and start on step 3.
1. Navigate to this [link](https://www.jetbrains.com/) and register for an account.
2. After verifying your status as a student, you should see this screen
![](../Assets/jetbrains_student_pack.png)
Click on the CLion link and you should arrive on this screen
![](../Assets/clion_screen.png)
3. Click on the download button and click on Download and .exe (For Windows users only, Mac should use .dmg)
![](../Assets/download_clion.png)
4. Run the installer for CLion and the setup wizard should open up  
![](../Assets/clion_installer.png)
5. Select **Next** and choose where to install the applications (The default location should be fine)
![](../Assets/install_location.png)
6. Next you'll be asked what preferences you want (These are all optional, they mainly wil help you access files through CLion instead of default applications like Notepad)
- Create Desktop Shortcut: Creates a shortcut icon on the desktop
- Update Context Menu: When you right click a file, it will show open with CLion
- Create Assocations: When you double click a file, it will open with CLion for the specified files types (ex. .c, .h, etc)  
Below are the ones I recommend  
![](../Assets/installation_options.png)
7. Next you'll be asked to choose a Start Menu Folder, the default is fine, so just click install and CLion should begin installing  
![](../Assets/start_menu_folder.png)
8. CLion should be successfully installed now   
![](../Assets/installation_finished.png)
## First Time Set up (Hello World)
1. When you open CLion for the first time, you'll be met with this popup  
![](../Assets/startup_import.png)  
This is just to import your styling settings, which you can if you have, but in most cases, you should choose do not import
2. Since there are no projects currently open, CLion will show the default screen given that you already have logged in
![](../Assets/clion_no_project.png)  
If you have not logged in yet, you'll be met with this screen
![](../Assets/log_in.png)  
Log in using you JB (JetBrains) account that you created earlier and you should have access to CLion now.
For our first CLion program, we can create a new project (I'll call this one HelloWorld)
Make sure that we are create a C++ executable and that we are using C++17
**Note**: For this class, we will be using C++17. It may not affect anything early on, but later, your code will not be able to compile if you are not using C++17.  
![](../Assets/hello_world.png)  
3. After creating your project, the Open Project Wizard will pop up because we do not have a toolchain set up yet. A toolchain is a set of tools that essentially helps us build your code. Included are often a compiler, linker, and assembler. Other toolchains may have more, but that are the basics.
It may look like this  
![](../Assets/open_project_wizard.png)  
Or look like this  
![](../Assets/bundled_mingw.png)  
4. You are free to install any toolchain you want, but the recommendations are Cygwin (recommended by the professor) and MinGW (recommended by me).
Since I use MinGW, we will be following the steps to install MinGW here.
5. Navigate to this [link](https://sourceforge.net/projects/mingw/) and click the green Download button to install the MinGW installer
![](../Assets/source_forge_installer.png)  
6. Run the installer  
![](../Assets/mingw_installer.png)    
![](../Assets/mingw_installer_landing.png)  
7. Any location is fine (Be sure to remember where you install it)  
![](../Assets/mingw_installer_location.png)
8. After installing, choose the following packages to install
- mingw-developer-tool
- mingw32-base
- mingw32-gcc-g++
- msys-base
9. In the top left, select Installation followed by Apply Changes
10. After the installation is completed  
![](../Assets/mingw_installer_apply_changes.png)
11. Now go back to CLion and Select the MinGW toolset (I saved mine in C:\MinGW)
![](../Assets/clion_toolset.png)
Hopefully, everything is detected (build tool, C compiler, C++ compiler)  
![](../Assets/mingw_installer_apply_changes.png)  
![](../Assets/clion_mingw_success.png)
And Click OK  
12. Now you should see about this screen
![](../Assets/clion_success.png)
Clicking the green play button on the top right will run the program and the program output will show below as "Hello World"
![](../Assets/clion_running.png)
## Opening your HW locally
1. Follow the instructions in the GitSetup folder to create a local repository   
2. Open Clion and choose Open  
![](../Assets/clion_open.png)
3. Open the overarching folder for the HW (usually will look like ece17-fa22-paX-username)   
Make sure that the CMakeLists.txt is in the first layer after you open that folder
4. CLion will then configure the CMakeLists.txt and now you can make changes

**Note**: It is a very good idea to add the .gitignore file from the discussion repository to your HW repo. This will eliminate any clutter in seeing the file differences.