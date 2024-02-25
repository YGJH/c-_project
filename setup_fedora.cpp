#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    char password[100];
    printf("Please input your password : ");
    fgets(password , sizeof(password) , stdin);
    system("sudo su");
    system(password);
    printf("log in superuser successfully !!\n");
    char install_vim[] = "sudo dnf install vim";
    char install_chewing[] = "sudo dnf install -y ibus ibus-chewing ibus-gtk2 ibus-gtk3 ibus-gtk4 ibus-qt\nimsettings-switch ibus\nSwitched input method to ibus";
    char install_nvidiaDrivers[] = "sudo dnf remove -y nvidia* --allowerasing\nsudo dnf upgrade -y --refresh\nsudo dnf config-manager --add-repo https://developer.download.nvidia.com/compute/cuda/repos/fedora39/x86_64/cuda-fedora39.repo\nsudo dnf config-manager --add-repo https://developer.download.nvidia.com/compute/cuda/repos/fedora39/x86_64/cuda-fedora39.repo\nsudo dnf module list nvidia-driver";
    //sudo dnf module install -y nvidia-driver:latest-dkms\n this command is something I m not sure wether it is necessary :D
    char install_braveBrowser[] = "sudo dnf install -y dnf-plugins-core\nsudo dnf config-manager --add-repo https://brave-browser-rpm-release.s3.brave.com/x86_64/\nsudo rpm --import https://brave-browser-rpm-release.s3.brave.com/brave-core.asc\nsudo dnf update\nsudo dnf install -y brave-browser";
    char install_vscode[] = "sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc\nsudo sh -c 'echo -e \"[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc\" > /etc/yum.repos.d/vscode.repo'";
    system(install_vim);
    printf("Finish install vim !!\n");
    system(install_braveBrowser);
    printf("Finish install brave browser !!\n");
    system(install_nvidiaDrivers);
    printf("Finish install nvidia drivers !!\n");
    system(install_vscode);
    printf("Finish install vscode !!\n");
    return 0;
}
