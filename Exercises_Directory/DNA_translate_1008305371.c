////////////////////////////////////////////////////////////
// CSC A48 - DNA alignment Pt. 1
//
// The goal of this assignment is to write a function that
// translates tripled (sets of 3) DNA nucleotide bases to
// the corresponding aminoacid.
//
// As a brief review of your Biology lessons, DNA is a double
// stranded chain of nucleic-acids, there are 4 types of
// nucleotides denoted by the letters:
//
// A, C, T, G
//
// The sequence of these nucleotides specifies the sequence
// in which aminoacids (the building blocks of proteins)
// are assembled into every single one of the proteins that
// make up the cells of most licing things (there are a 
// few that do not use DNA, opting instead to use the single
// stranded version called RNA, viruses tend to be sneaky
// that way!)
//
// Each set of 3 nucleotides specifies one aminoacid in
// a protein's specification.
//
// The goal of this exercise is for you to write a small
// function that takes in a DNA sequence (a string made up
// of letters ATCG in some sequence) and determines the
// corresponding sequence of aminoacids. Below, you will
// find a table listing each aminoacid, and the sequences
// of DNA nucleotides that specify that aminoacid.
// 
// Note that many aminoacids can be specified by more than
// one triplet!
//
//  Aminoacid   Single letter name	Triplets
//  Isoleucine 		I 		ATT, ATC, ATA
//  Leucine 		L 		CTT, CTC, CTA, CTG, TTA, TTG
//  Valine 		V 		GTT, GTC, GTA, GTG
//  Phenylalanine 	F 		TTT, TTC
//  Methionine 		M 		ATG
//  Cysteine 		C 		TGT, TGC
//  Alanine 		A 		GCT, GCC, GCA, GCG
//  Glycine 		G 		GGT, GGC, GGA, GGG
//  Proline 		P 		CCT, CCC, CCA, CCG
//  Threonine 		T		ACT, ACC, ACA, ACG
//  Serine 		S 		TCT, TCC, TCA, TCG, AGT, AGC
//  Tyrosine 		Y 		TAT, TAC
//  Tryptophan 		W 		TGG
//  Glutamine 		Q 		CAA, CAG
//  Asparagine 		N 		AAT, AAC
//  Histidine 		H 		CAT, CAC
//  Glutamic acid 	E 		GAA, GAG
//  Aspartic acid 	D 		GAT, GAC
//  Lysine 		K 		AAA, AAG
//  Arginine 		R 		CGT, CGC, CGA, CGG, AGA, AGG
//
//  Your task is to determine whether two DNA sequences use the
//  same number of each type of aminoacid (the order of the
//  amino-acids doesn't matter here).
//  To that end, you need to write a function that
//  takes a DNA sequence and converts it to the corresponding
//  sequence of aminoacids, for instance if the input sequence is:
//
//  AAGGAGTGTTTT
//
//  Your function must return
//
//  KECF
//
//  Then you need to write a function that takes in two DNA
//  sequences and determines whether they produce the same
//  numbers of each aminoacid. For example, if the sequence
//  of aminoacids for each of the input DNA sequences is
//
//  AATVKFAA    and    TAAVKAAF
//
//  The function must return 1 (they produce the same number
//  of each aminoacid). However, if the aminoacid sequences
//  are
//
//  TVFAAKVV    and    ECVAATFK
//
//  the function will return 0 (not the same number of each
//  aminoacid).
//
// (c) F. Estrada, March, 2022
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Helper Function: DNA Sequences -> Amino Acid Sequences (I know it's ugly, please don't judge) //
char DNA_to_Amino(char tmp_nucleotide[]){
	if (memcmp(tmp_nucleotide, "ATT", 3) == 0 || memcmp(tmp_nucleotide, "ATC", 3) == 0 || memcmp(tmp_nucleotide, "ATA", 3) == 0) 
	return 'I';

	if (memcmp(tmp_nucleotide, "CTT", 3) == 0 || memcmp(tmp_nucleotide, "CTC", 3) == 0 || memcmp(tmp_nucleotide, "CTA", 3) == 0 || memcmp(tmp_nucleotide, "CTG", 3) == 0 || memcmp(tmp_nucleotide, "TTA", 3) == 0 || memcmp(tmp_nucleotide, "TTG", 3) == 0) 
	return 'L';

	if (memcmp(tmp_nucleotide, "GTT", 3) == 0 || memcmp(tmp_nucleotide, "GTC", 3) == 0 || memcmp(tmp_nucleotide, "GTA", 3) == 0 || memcmp(tmp_nucleotide, "GTG", 3) == 0) 
	return 'V';

	if (memcmp(tmp_nucleotide, "TTT", 3) == 0 || memcmp(tmp_nucleotide, "TTC", 3) == 0) 
	return 'F';

	if (memcmp(tmp_nucleotide, "ATG", 3) == 0)
	return 'M';

	if (memcmp(tmp_nucleotide, "TGT", 3) == 0 || memcmp(tmp_nucleotide, "TGC", 3) == 0)
	return 'C';

	if (memcmp(tmp_nucleotide, "GCT", 3) == 0 || memcmp(tmp_nucleotide, "GCC", 3) == 0 || memcmp(tmp_nucleotide, "GCA", 3) == 0 || memcmp(tmp_nucleotide, "GCG", 3) == 0)
	return 'A';

	if (memcmp(tmp_nucleotide, "GGT", 3) == 0 || memcmp(tmp_nucleotide, "GGC", 3) == 0 || memcmp(tmp_nucleotide, "GGA", 3) == 0 || memcmp(tmp_nucleotide, "GGG", 3) == 0)
	return 'G';

	if (memcmp(tmp_nucleotide, "CCT", 3) == 0 || memcmp(tmp_nucleotide, "CCC", 3) == 0 || memcmp(tmp_nucleotide, "CCA", 3) == 0 || memcmp(tmp_nucleotide, "CCG", 3) == 0)
	return 'P';

	if (memcmp(tmp_nucleotide, "ACT", 3) == 0 || memcmp(tmp_nucleotide, "ACC", 3) == 0 || memcmp(tmp_nucleotide, "ACA", 3) == 0 || memcmp(tmp_nucleotide, "ACG", 3) == 0)
	return 'T';

	if (memcmp(tmp_nucleotide, "TCT", 3) == 0 || memcmp(tmp_nucleotide, "TCC", 3) == 0 || memcmp(tmp_nucleotide, "TCA", 3) == 0 || memcmp(tmp_nucleotide, "TCG", 3) == 0 || memcmp(tmp_nucleotide, "AGT", 3) == 0 || memcmp(tmp_nucleotide, "AGC", 3) == 0)
	return 'S';

	if (memcmp(tmp_nucleotide, "TAT", 3) == 0 || memcmp(tmp_nucleotide, "TAC", 3) == 0)
	return 'Y';

	if (memcmp(tmp_nucleotide, "TGG", 3) == 0)
	return 'W';

	if (memcmp(tmp_nucleotide, "CAA", 3) == 0 || memcmp(tmp_nucleotide, "CAG", 3) == 0)
	return 'Q';

	if (memcmp(tmp_nucleotide, "AAT", 3) == 0 || memcmp(tmp_nucleotide, "AAC", 3) == 0)
	return 'N';

	if (memcmp(tmp_nucleotide, "CAT", 3) == 0 || memcmp(tmp_nucleotide, "CAC", 3) == 0)
	return 'H';

	if (memcmp(tmp_nucleotide, "GAA", 3) == 0 || memcmp(tmp_nucleotide, "GAG", 3) == 0)
	return 'E';

	if (memcmp(tmp_nucleotide, "GAT", 3) == 0 || memcmp(tmp_nucleotide, "GAC", 3) == 0)
	return 'D';

	if (memcmp(tmp_nucleotide, "AAA", 3) == 0 || memcmp(tmp_nucleotide, "AAG", 3) == 0)
	return 'K';

	if (memcmp(tmp_nucleotide, "CGT", 3) == 0 || memcmp(tmp_nucleotide, "CGC", 3) == 0 || memcmp(tmp_nucleotide, "CGA", 3) == 0 || memcmp(tmp_nucleotide, "CGG", 3) == 0 || memcmp(tmp_nucleotide, "AGA", 3) == 0 || memcmp(tmp_nucleotide, "AGG", 3) == 0)
	return 'R';
}

void DNA_sequencing(char inputDNA[1024], char outputAminoAcids[1024]){
    // This function receives two strings, one that contains a sequence
    // of DNA nucleotides (which MUST be composed of the letters
    // ACGT, no spaces or other symbols can appear here!), and
    // updates an initially empty string 'outputAminoAcids' with the
    // sequence of aminoacids corresponding to the input DNA sequence
    //
    // Try to make this function as compact (fewer lines of code, more
    // elegant, easier to read code) as possible. APply what you've
    // learned in Exercises 6-8, all of which helped you practice
    // using strings!

    // To Do:
    // Complete this function

	char tmp_nucleotide[4];
	int mult_three = 0;

	for (int i = 0; i < 13; i++){
		tmp_nucleotide[0] = inputDNA[mult_three * 3];
		tmp_nucleotide[1] = inputDNA[(mult_three * 3) + 1];
		tmp_nucleotide[2] = inputDNA[(mult_three * 3) + 2];

		mult_three++;
		outputAminoAcids[i] = DNA_to_Amino(tmp_nucleotide);
	}
}

int amino_matching(char inputDNA1[1024], char inputDNA2[1024]){
    // This function receives two strings representing DNA
    // sequences. It returns 1 if the sequences produce the
    // same number of each type of aminoacid. Think carefully
    // about the best (simplest?) way to to this.

    // To Do:
    // Complete this function

	int temp1[256] = {0};
	int temp2[256] = {0};
	int i; // Let's just initialize the var once...

	for (i = 0; inputDNA1[i] && inputDNA2[i]; i++) {
		temp1[inputDNA1[i]]++;
		temp2[inputDNA2[i]]++;
	}

	if (inputDNA1[i] || inputDNA2[i]) return 0;
	
	for (i = 0; i < 256; i++){
		if (temp1[i] != temp2[i]) return 0;
	}
	
	return 1;
}

#ifndef __testing

int main()
{
	char DNAseq1[1024]="CTTATTGTTCCAATGTGGCGGCACTACACGTGCGTTATC";
	char DNAseq2[1024]="ATTTATTGTACATATCATCGTTGGATGCCCGTAATATTG";
        char DNAseq3[1024]="ATCGTTTGCACGTACCACCGGTGGATGCCAGTTATTCTT";
	char aminoAcids[1024]="";

	printf("Input DNA sequence 1: %s\n",DNAseq1);
	DNA_sequencing(DNAseq1,aminoAcids);
	printf("Output aminoacid sequence 1: %s\n",aminoAcids);

	printf("Input DNA sequence 2: %s\n",DNAseq2);
	DNA_sequencing(DNAseq2,aminoAcids);
	printf("Output aminoacid sequence 2: %s\n",aminoAcids);

	printf("Input DNA sequence 3: %s\n",DNAseq3);
	DNA_sequencing(DNAseq3,aminoAcids);
	printf("Output aminoacid sequence 3: %s\n",aminoAcids);

	if (amino_matching(DNAseq1,DNAseq2)==1)
	{
		printf("Sequence 1 matches sequence 2 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 2 in aminoacids\n");
	}

	if (amino_matching(DNAseq1,DNAseq3)==1)
	{
		printf("Sequence 1 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 3 in aminoacids\n");
	}

	if (amino_matching(DNAseq2,DNAseq3)==1)
	{
		printf("Sequence 2 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 2 does not match sequence 3 in aminoacids\n");
	}

	return 0;
}

#endif
