#include <bits/stdc++.h>

using namespace std;

class vehicle{
    int vehicleID;
    static int id;
    string vehicleType;
    int entryTime;
    int parkingDuration;
    double parkingFee;
    bool isOccupied;
    

    public:
    vehicle(){
        vehicleID=id++;
        vehicleType="";
        entryTime=0;
        parkingDuration=1;
        parkingFee=0;
        isOccupied=false;
    }
    vehicle(string type, int time, int dura, bool occ){
        vehicleID=id++;
        setType(type);
        setTime(time);
        setDura(dura);
        parkingFee=0;
        isOccupied=occ;
    }

    void setType(string type){
    for(int i=0;i<type.length();i++){
        type[i]=tolower(type[i]);
    }
    if(type=="car"){
        vehicleType="Car";
    }else if(type=="bicycle"){
        vehicleType="Bicycle";
    }else if(type=="motorcycle"){
        vehicleType="Motorcycle";
    }else{
        cout<<"Khong hop le";
        return;
    }
    
}
void setTime(int time){
    if(time>=0&&time<=23){
        entryTime=time;
    }else{
        return;
    }
}
void setDura(int dura){
    if(dura>=1&&dura<=23){
        parkingDuration=dura;
    }else{
        return;
    }
}


int getvehicleID(){
    return vehicleID;
}
string getVehicleType(){
    return vehicleType;
}
int getEntryTime(){
    return entryTime;
}
int getParkingDuration() {
    return parkingDuration;
}
double getParkingFee() {
    return parkingFee;
}
bool getIsOccupied() {
    return isOccupied;
}

void caculateFee(){
    string typefee=vehicleType;
    int fee=0;
    if(typefee=="Car"){
        fee=6;
    }else if(typefee=="Bicycle"){
        fee=2;
    }else if(typefee=="Motorcycle"){
        fee=4;
    }

    if((entryTime>=6&&entryTime<10)||(entryTime>=15&&entryTime<19)){
            if(parkingDuration>=2){
                parkingFee= 2*fee*(1.3)+(parkingDuration-2)*fee*0.9;
            }else{
                parkingFee= (parkingDuration)*fee+fee*(0.3);
            }
        }else{
            if(parkingDuration>=2){
                parkingFee= 2*fee*(0.95)+(parkingDuration-2)*fee*0.9;
            }else{
                parkingFee= (parkingDuration)*fee-fee*(0.05);
            }
        }
}
};

class ParkingLot{
    int parkID;
    char size;
    vehicle vehicle1,vehicle2,vehicle3;
    bool hasVehicle1,hasVehicle2,hasVehicle3;

    public:
    ParkingLot(){
        parkID=0;
        size='S';
        hasVehicle1=false;
        hasVehicle2=false;
        hasVehicle3=false;
    }
    ParkingLot(int id,char sz){
        parkID=id;
        size=sz;
        hasVehicle1=false;
        hasVehicle2=false;
        hasVehicle3=false;
    }

    bool addVehicle(const vehicle& v){
        if(!hasVehicle1){
            vehicle1=v;
            hasVehicle1=true;
            return true;
        }
        if(size=='S'){
            return false;
        }
        if(!hasVehicle2){
            vehicle2=v;
            hasVehicle2=true;
            return true;
        }
        if(size=='M'){
            return false;
        }
        if(!hasVehicle3){
            vehicle3=v;
            hasVehicle3=true;
            return true;
        }
        return false;
    }
    bool removeVehicle(int ID){
        if(hasVehicle1&&vehicle1.getvehicleID()==ID){
            hasVehicle1=false;
            return true;
        }
        if(hasVehicle2&&vehicle2.getvehicleID()==ID){
            hasVehicle2=false;
            return true;
        }
        if(hasVehicle3&&vehicle3.getvehicleID()==ID){
            hasVehicle3=false;
            return true;
        }
        return false;
    }
    void displayLotInfo(){
        cout<<"ID bai: "<<parkID<<endl;
        cout<<"Kich thuoc bai: "<<size<<endl;
        if(hasVehicle1){
            cout<<"Vi tri 1: "<<vehicle1.getvehicleID()<<endl;
        }
        if(hasVehicle2){
            cout<<"Vi tri 2: "<<vehicle2.getvehicleID()<<endl;
        }
        if(hasVehicle3){
            cout<<"Vi tri 3: "<<vehicle3.getvehicleID()<<endl;
        }
    }
    int getParkID() {
    return parkID;
}

    void DisplayByType(string type){
        if(hasVehicle1 && vehicle1.getVehicleType() == type){
             cout<<"Ma xe: "<<vehicle1.getvehicleID()<<endl;
        }
        if(hasVehicle2 && vehicle2.getVehicleType() == type){
             cout<<"Ma xe: "<<vehicle2.getvehicleID()<<endl;
        }
        if(hasVehicle3 && vehicle3.getVehicleType() == type){
             cout<<"Ma xe: "<<vehicle3.getvehicleID()<<endl;
        }
    }   

    void feeReport(double& totalfee, int& count){
        if(hasVehicle1){
            totalfee +=vehicle1.getParkingFee();
            count++;
        }
        if(hasVehicle2){
            totalfee +=vehicle2.getParkingFee();
            count++;
        }
        if(hasVehicle3){
            totalfee +=vehicle3.getParkingFee();
            count++;
        }
    }
};

class SystemInterface{
    ParkingLot parkinglot1,parkinglot2,parkinglot3;
    bool hasLot1,hasLot2,hasLot3;

    public:
    SystemInterface(){
        hasLot1 = false;
        hasLot2 = false;
        hasLot3 = false;
    }
    
    void addvehicle(ParkingLot& lot){
            string type;
            int time,dura;
            cout<<"Nhap loai xe: "; cin>>type;
            cout<<"Nhap gio vao bai: "; cin>>time;
            cout<<"Nhap thoi gian do xe:"; cin>>dura;
            vehicle v(type,time,dura,true);
            v.caculateFee();
            if(lot.addVehicle(v)){
                cout<<"Them xe thanh cong";
            }else{
                cout<<"Bai da day";
            }
        }
    
    void runMenu(){
        int n;
        do{
            cout<<"\n-----QUAN LY BAI DO XE-----\n";
            cout<<"1.Tao bai do xe moi\n";
            cout<<"2.Them xe vao bai do\n";
            cout<<"3.Xoa bai do xe\n";
            cout<<"4.lay xe ra khoi bai\n";
            cout<<"5.Hien thi danh sach cac bai do xe\n";
            cout<<"6.Hien thi xe theo bai do\n";
            cout<<"7.Liet ke xe theo loain\n";
            cout<<"8.Bao cao phi do xe trung binh\n";
            cout<<"9.Thoat\n";

            cout<<"NHAP LUA CHON: ";
            cin>>n;
            switch(n){
                int idLot;
                case 1:{
                    char size;
                    cout<<"Nhap ID: ";cin>>idLot;
                    cout<<"Nhap Size(S/M/L): ";cin>>size;
                    if(size!='S'&&size!='M'&&size!='L'){
                        cout<<"Khong hop le";
                        break;
                    }
                    if((hasLot1 && parkinglot1.getParkID()==idLot)||
                        (hasLot2 && parkinglot2.getParkID()==idLot)||
                        (hasLot3 && parkinglot3.getParkID()==idLot))
                    {
                        cout<<"ID bai xe da ton tai\n";
                        return;
                    }
                    if(!hasLot1){
                        parkinglot1=ParkingLot(idLot,size);
                        hasLot1=true;
                    }
                    else if(!hasLot2){
                        parkinglot2=ParkingLot(idLot,size);
                        hasLot2=true;
                    }
                    else if(!hasLot3){
                        parkinglot3=ParkingLot(idLot,size);
                        hasLot3=true;
                    }else{
                        cout<<"Bai do xe da day";
                        return;
                    }
                    break;
                    }
                case 2:
                    {
                        cout<<"Nhap ID bai do xe: "; cin>> idLot;
                    if (hasLot1 && parkinglot1.getParkID() == idLot){
                        addvehicle(parkinglot1);
                    }
                    else if (hasLot2 && parkinglot2.getParkID() == idLot){
                        addvehicle(parkinglot2);
                    }
                    else if (hasLot3 && parkinglot3.getParkID() == idLot){
                        addvehicle(parkinglot3);
                    }
                    else{
                        cout<<"Khong tim thay bai do xe";
                    }
                    break;
                    }
                case 3:
                    {
                        cout<<"Nhap parkID can xoa: "; cin>>idLot;
                    if (hasLot1 && parkinglot1.getParkID() == idLot) {
                        hasLot1 = false;
                        cout<<"Xoa bai do thanh cong!\n";
                    }
                    else if (hasLot2 && parkinglot2.getParkID() == idLot) {
                        hasLot2 = false;
                        cout<<"Xoa bai do thanh cong!\n";
                    }
                    else if (hasLot3 && parkinglot3.getParkID() == idLot) {
                        hasLot3 = false;
                        cout<<"Xoa bai do thanh cong!\n";
                    }
                    else{
                        cout<<"Khong tim thay bai";
                    }
                    break;
                    }
                case 4:
                    {
                        int idx; 
                    cout<<"Nhap ID bai do xe: ";cin>> idLot;
                    cout<<"Nhap ID xe: ";cin>>idx;
                    if(hasLot1 && parkinglot1.getParkID() == idLot){
                        if(parkinglot1.removeVehicle(idx)){
                            cout<<"Lay xe thanh cong";
                        }else{
                            cout<<"Khong tim thay xe";
                        }
                    }else if(hasLot2 && parkinglot2.getParkID() == idLot){
                        if(parkinglot2.removeVehicle(idx)){
                            cout<<"Lay xe thanh cong";
                        }else{
                            cout<<"Khong tim thay xe";
                        }
                    }else if(hasLot3 && parkinglot3.getParkID() == idLot){
                        if(parkinglot3.removeVehicle(idx)){
                            cout<<"Lay xe thanh cong";
                        }else{
                            cout<<"Khong tim thay xe";
                        }
                    }else{
                        cout<<"Khong tim thay bai do xe";
                    }
                    break;
                    }
                case 5:
                        {
                            if(hasLot1){
                            parkinglot1.displayLotInfo();
                        }
                        if(hasLot2){
                            parkinglot2.displayLotInfo();
                        } 
                        if(hasLot3){
                            parkinglot3.displayLotInfo();
                        }
                        if(!hasLot1&&!hasLot2&&!hasLot3){
                            cout<<"Chua co bai xe";
                        } 
                        break;
                        }
                case 6:
                       {
                         cout<<"Nhap ID bai do xe: ";cin>>idLot;
                        if(hasLot1&&parkinglot1.getParkID()==idLot){
                            parkinglot1.displayLotInfo();
                        }else if(hasLot2&&parkinglot2.getParkID()==idLot){
                            parkinglot2.displayLotInfo();
                        }else if(hasLot3&&parkinglot3.getParkID()==idLot){
                            parkinglot3.displayLotInfo();
                        }else{
                            cout<<"Khong tim thay bai do xe";
                        }
                        break;
                       }
                case 7: 
                        {
                        string type;
                        cout<<"Nhap loai xe: "; cin>>type;
                        if(hasLot1){
                            parkinglot1.DisplayByType(type);
                        }
                        if(hasLot2){
                            parkinglot2.DisplayByType(type);
                        }
                        if(hasLot3){
                            parkinglot3.DisplayByType(type);
                        }
                        break;
                        }
                case 8:
                       {
                         double totalfee=0;
                        int count=0;
                        if(hasLot1){
                            parkinglot1.feeReport(totalfee,count);
                        }
                        if(hasLot2){
                            parkinglot2.feeReport(totalfee,count);
                        }
                        if(hasLot3){
                            parkinglot3.feeReport(totalfee,count);
                        }
                        if(count==0){
                            cout<<"Chua co xe";
                            break;
                        }
                        cout<<"Tong chi phi do xe: "<< totalfee<<endl;
                        cout<<"So xe: "<<count<<endl;
                        cout<<"Phi do xe trung binh: "<<totalfee/count;
                        break;
                       }
                case 9:
                        break;
                default: 
                        cout<<"Lua chon khong hop le";
            }
        }while(n!=9);
    }    
};
int vehicle::id=1;
int main(){
    SystemInterface sys;
    sys.runMenu();

    return 0;
}