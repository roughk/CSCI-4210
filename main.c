#include <stdio.h>
#include <stdlib.h> 
 
// EXAMPLE DATA STRUCTURE DESIGN AND LAYOUT FOR CLA
#define input_size 1024
#define block_size 8

//Do not touch these defines
#define digits (input_size+1)
#define bits digits*4
#define ngroups bits/block_size
#define nsections ngroups/block_size
#define nsupersections nsections/block_size

//Global definitions of the various arrays used in steps for easy access
int gi[bits] = {0};
int pi[bits] = {0};
int ci[bits] = {0};
int ggj[ngroups] = {0};
int gpj[ngroups] = {0};
int gcj[ngroups] = {0};
int sgk[nsections] = {0};
int spk[nsections] = {0};
int sck[nsections] = {0};
int ssgl[nsupersections] = {0} ;
int sspl[nsupersections] = {0} ;
int sscl[nsupersections] = {0} ;
int sumi[bits] = {0};

//Integer array of inputs in binary form
int bin1[bits];
int bin2[bits];

//Character array of inputs in hex form
char hex1[input_size];
char hex2[input_size];

//converts the input hex char values to binary int arrays
int hextobin(){
	int num;
	int i;
	//converts hex numbers to integers, then to binary. Results in a reverse order binary number
	for(i = 0; i< input_size; i++){
		num = strtol(hex1[i], NULL, 16);
		if(num >= 8){
			bin1[(i*4)+3] = 1;
			num = num-8;
		}
		if(num >= 4){
			bin1[(i*4)+2] = 1;
			num = num-4;
		}
		if(num >= 2){
			bin1[(i*4)+1] = 1;
			num = num-2;
		}
		if(num >= 1){
			bin1[(i*4)] = 1;
			num = num-1;
		}
	}
	
	//converts hex numbers to integers, then to binary. Results in a reverse order binary number
	for(i = 0; i< input_size; i++){
		num = strtol(hex2[i], NULL, 16);
		if(num >= 8){
			bin2[(i*4)+3];
			num = num-8;
		}
		if(num >= 4){
			bin2[(i*4)+2];
			num = num-4;
		}
		if(num >= 2){
			bin2[(i*4)+1];
			num = num-2;
		}
		if(num >= 1){
			bin2[(i*4)];
			num = num-1;
		}
	}

	return 0;
}//hextobin()

//outputs sumi asa hexidecimal string
int outut_bintohex(){
	int num;
	int i;
	int index;
	
	//reverse order of binary numbers
	for(i = 0; i < input_size*2; i++){
		num = sumi[i];
		sumi[i] = sumi[bits-i];
		sumi[bits-i] = num;
	}
	//converts binary numbers to integers, then to hex.
	for(i = 0; i< input_size; i++){
		num = 0;
		index = i*4;
		if(sumi[idex+3] == 1){
			num = num+8
		}
		if(sumi[idex+2] == 1){
			num = num+4;
		}
		if(sumi[idex+1] == 1){
			num = num+2;
		}
		if(sumi[idex] == 1){
			num = num+1;
		}
		printf("%X", num)
	}
	
	//reverse order of binary numbers
	for(i = 0; i < input_size*2; i++){
		num = sumi[i];
		sumi[i] = sumi[bits-i];
		sumi[bits-i] = num;
	}

	return 0;
}//hextobin()

//generates gi and pi and stores them in their respective arrays
int generate_gi_pi(){
	int i;
	for(i = 0; i < bits; i++){
		gi[i] = bin1[i] & bin2[i];
		pi[i] = bin1[i] | bin2[i];
	}
	return 0;
}//generate_gi_pi()

//generates ggj and gpj and stores them in their respective arrays
int generate_ggj_gpj(){
	int j, i;
	for(j = 0; j < ngroups; j++){
		i = 8*j;
		ggj[j]=   (gi[i+7])
				| (pi[i+7] & gi[i+6] )
				| (pi[i+7] & pi[i+6] & gi[i+5] )
				| (pi[i+7] & pi[i+6] & pi[i+5] & gi[i+4] )
				| (pi[i+7] & pi[i+6] & pi[i+5] & pi[i+4] & gi[i+3] )
				| (pi[i+7] & pi[i+6] & pi[i+5] & pi[i+4] & pi[i+3] & gi[i+2] )
				| (pi[i+7] & pi[i+6] & pi[i+5] & pi[i+4] & pi[i+3] & pi[i+2] & gi[i+1] )
				| (pi[i+7] & pi[i+6] & pi[i+5] & pi[i+4] & pi[i+3] & pi[i+2] & pi[i+2] & gi[i] );
				
		gpj[j] =  pi[i+7] & pi[i+6] & pi[i+5] & pi[i+4] & pi[i+3] & pi[i+2] & pi[i+1] & pi[i];
	}
	return 0;
}//generate_ggj_gpi()

//generates sgk and spk, and stores them in their respective arrays
int generate_sgk_spk(){
	int k, j;
	for(k = 0; k < nsections; k++){
		j = 8*k;
		sgk[k]=   (ggj[j+7])
				| (gpj[j+7] & ggj[j+6] )
				| (gpj[j+7] & gpj[j+6] & ggj[j+5] )
				| (gpj[j+7] & gpj[j+6] & gpj[j+5] & ggj[j+4] )
				| (gpj[j+7] & gpj[j+6] & gpj[j+5] & gpj[j+4] & ggj[j+3] )
				| (gpj[j+7] & gpj[j+6] & gpj[j+5] & gpj[j+4] & gpj[j+3] & ggj[j+2] )
				| (gpj[j+7] & gpj[j+6] & gpj[j+5] & gpj[j+4] & gpj[j+3] & gpj[j+2] & ggj[j+1] )
				| (gpj[j+7] & gpj[j+6] & gpj[j+5] & gpj[j+4] & gpj[j+3] & gpj[j+2] & gpj[j+2] & ggj[j] );
				
		spk[k] =  gpj[j+7] & gpj[j+6] & gpj[j+5] & gpj[j+4] & gpj[j+3] & gpj[j+2] & gpj[j+1] & gpj[j];
	}
	return 0;
}//generate_sgk_spk()

//generates ssgl and sspl and stores them in their respective arrays
int generate_ssgl_sspl(){
	int l, k;
	for(l = 0; l < nsupersections; l++){
		k = 8*l;
		ssgl[l]=  (sgk[k+7])
				| (spk[k+7] & sgk[k+6] )
				| (spk[k+7] & spk[k+6] & sgk[k+5] )
				| (spk[k+7] & spk[k+6] & spk[k+5] & sgk[k+4] )
				| (spk[k+7] & spk[k+6] & spk[k+5] & spk[k+4] & sgk[k+3] )
				| (spk[k+7] & spk[k+6] & spk[k+5] & spk[k+4] & spk[k+3] & sgk[k+2] )
				| (spk[k+7] & spk[k+6] & spk[k+5] & spk[k+4] & spk[k+3] & spk[k+2] & sgk[k+1] )
				| (spk[k+7] & spk[k+6] & spk[k+5] & spk[k+4] & spk[k+3] & spk[k+2] & spk[k+2] & sgk[k] );
				
		sspl[l] =  spk[k+7] & spk[k+6] & spk[k+5] & spk[k+4] & spk[k+3] & spk[k+2] & spk[k+1] & spk[k];
	}
	return 0;
}//generate

//generates ci and stores them in their respective array
int generate_ci(){
	int i;
	for(i = 0; i < bits; i++){
		if (i == 0)
			ci[i] = gi[i] | (pi[i] & 0);
		else (i % 8 == 0)
			ci[i] = gi[i] | (pi[i] & gcj[(i/8)-1]);
		else
			ci[i] = gi[i] | (pi[i] & ci[i-1]);
	} 
	return 0;
}//generate_ci()

//generates gcj and stores them in their respective array
int generate_gcj(){
	int j;
	for(j = 0; j < ngroups; j++){
		if (j == 0)
			gcj[i] = ggj[j] | (gpj[j] & 0);
		else(j % 8 == 0)
			gcj[i] = ggj[j] | (gpj[j] & sck[(l/8)-1]);
		else
			gcj[j] = ggj[j] | (gpj[j] & gcj[j-1]);
	} 
	return 0;
}//generate_gcj()

//generates sck and stores them in their respective array
int generate_sck(){
	int k;
	for(k = 0; k < nsections; k++){
		if (k == 0)
			sck[k] = sgk[k] | (spk[k] & 0);
		else (k % 8 == 0)
			sck[k] = sgk[k] | (spk[k] & sscl[(k/8)-1]);
		else
			sck[k] = sgk[k] | (spk[k] & sck[k-1]);
	} 
	return 0;
}//generate_sck()

//generates sscl and stores them in their respective array
int generate_sscl(){
	int l;
	sscl[0] = ssgl[0] | (sspl[0]&0);
	for(l = 1; l < nsupersections; l++){
		sscl[l] = ssgl[l] | (sspl[l]& sscl[l-1]);
	} 
	return 0;
}//generate_sscl()


//two bit carry adder function, processes bin1, bin2 and ci to create sumi
int add(){
	int i;
	sum[0] = bin1[0] ^ bin2[0] ^ 0;
	for(i = 1; i< bits; i++){
		sumi[0] = bin1[0] ^ bin2[0] ^ ci[i-1] ;
	}
  return 0;
}


int main(int argc, char *argv[]) {
	//load strings from the given file
	scanf("%s", hex1);
	scanf("%s", hex2);
	
	//process strings into usable binary arrays
	hextobin();

	//steps 1 to 4
	generate_gi_pi();
	generate_ggj_gpj();
	generate_sgk_spk();
	generate_ssgl_sspl();
	
	//steps 5 to 8
	generate_sscl();
	generate_sck();
	generate_gcj();
	generate_ci();
	
	//step 9
	add();

	return 0;
}








