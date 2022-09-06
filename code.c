#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
maintenant(int *annee, int *mois, int *jour, int *heure, int *minutes)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    *annee = tm->tm_year + 1900;
    *mois = tm->tm_mon + 1;
    *jour = tm->tm_mday;
    *heure = tm->tm_hour;
    *minutes = tm->tm_min;
}

int
main()
{
    int annee_maintenant, mois_maintenant, jour_maintenant,
        heure_maintenant, min_maintenant;
    int annee, mois, jour, heure, min;
    int rc, n, i; 
    int min_actuel, min_journee , min_rdv , rdv_matin, rdv_aprem, rdv_soir, rdv_nuit, rdv_jour, rdv_passe, rdv_futur, timer,timer2,timer3,bissextile_maintenant,bissextile,noel;
    noel=0;
    bissextile_maintenant=0;
    bissextile=0;
    timer3=0;
    timer2=0;
    timer =0;
    rdv_jour = 0;
    rdv_passe = 0;
    rdv_futur =0 ;
    rdv_matin = 0 ;
    rdv_aprem = 0;
    rdv_soir = 0;
    rdv_nuit = 0;
    min_rdv = 0 ;
    min_actuel = 0 ;
    min_journee = 60*24 ;
    char intitule[512];

    maintenant(&annee_maintenant, &mois_maintenant, &jour_maintenant,
	       &heure_maintenant, &min_maintenant);
    
    printf("Aujourd'hui nous sommes le %d ",jour_maintenant);
    if(mois_maintenant==1) {
	printf("janvier");
    }else if(mois_maintenant==2) {
	printf("février");
    }else if(mois_maintenant==3) {
	printf("mars");
    }else if(mois_maintenant==4) {
	printf("avril");
    }else if(mois_maintenant==5) {
	printf("mai");
    }else if(mois_maintenant==6) {
	printf("juin");
    }else if(mois_maintenant==7) {
	printf("juillet");
    }else if(mois_maintenant==8) {
	printf("août");
    }else if(mois_maintenant==9) {
	printf("septembre");
    }else if(mois_maintenant==10){
	printf("octobre");
    }else if(mois_maintenant==11) {
	printf("novembre");
    }else if(mois_maintenant==12) {
	printf("décembre");
    }else{
	printf("mois inconnu");
    }
    printf(" %d, il est %dh%02d.\n", annee_maintenant, heure_maintenant, min_maintenant);
    
    if(mois_maintenant>12 || mois_maintenant<1) {
	printf("\nErreur de mois dans la date actuelle\n");
    }else if((mois_maintenant==1 || mois_maintenant==3 || mois_maintenant==5 || mois_maintenant==7 || mois_maintenant==8 || mois_maintenant==10 || mois_maintenant==12) && (jour_maintenant>31)){
	printf("\nJour inexistant pour le mois donné dans la date acutelle.\n");
    }else if((mois_maintenant==4 || mois_maintenant==6 || mois_maintenant==9 || mois_maintenant==11) && (jour_maintenant>30)){
	printf("\nJour inexistant pour le mois donné dans la date actuelle.\n");
    }else if(mois_maintenant==2 && bissextile_maintenant==1 && jour_maintenant>29){
	printf("\nJour inexistant pour le mois donné dans la date actuelle.\n");
    }else if(mois_maintenant==2 && bissextile_maintenant==0 && jour_maintenant>28){
	printf("\nJour inexistant pour l'année dans la date actuelle.\n");
    }else if(jour_maintenant<=0){
	printf("\nJour actuel inexistant.\n");
    }else if(heure_maintenant>=24 || heure_maintenant<0) {
	printf("\nHeure inexistante pour la date actuelle.\n");
    }else if(min_maintenant>=60 || min_maintenant<0){
	printf("\nMinutes inexistantes pour la date actuelle.\n");
    }
    
    if((annee_maintenant%400==0)|| (annee_maintenant%4==0 && annee_maintenant%100!=0)) {
	printf("\nNous sommes dans une année Bissextile.\n");
    }
    
    if((mois_maintenant==3 && jour_maintenant>=21)||(mois_maintenant>3 && mois_maintenant<6)||(mois_maintenant==6 && jour_maintenant<21)){
	printf("\nNous sommes au Printemps, pensez à vous couvrir le temps change vite\n");
    }else if((mois_maintenant==6 && jour_maintenant>=21)||(mois_maintenant>6 && mois_maintenant<9)||(mois_maintenant==9 && jour_maintenant<22)){
	printf("\nNous sommes en Eté, profitez de vos vacances et du beau temps \n");
    }else if((mois_maintenant==9 && jour_maintenant>=22)||(mois_maintenant>9 && mois_maintenant<12)||(mois_maintenant==12 && jour_maintenant<21)){
	printf("\nNous sommes en Automne, sortez couvert la pluie n'est jamais très loin\n");
    }else if(((mois_maintenant==12 && jour_maintenant>=21 && jour_maintenant<31))||(mois_maintenant<3)||(mois_maintenant==3 && jour_maintenant<21)){
	printf("\nNous sommes en Hivers, il fait froid mais les beaux jours reviendront bientôt.\n");
    }else{
	printf("\nVous n'appartenez à aucune saison.\n");
    }
    
    if((mois_maintenant==1&&jour_maintenant>=21)||(mois_maintenant==2&&jour_maintenant<=19)){
	printf("Nous sommes dans la période du Verseau, signe associé : l'Air\n");
    }else if((mois_maintenant==2&&jour_maintenant>=20)||(mois_maintenant==3&&jour_maintenant<=20)) {
	printf("Nous sommes dans la période des Poisson, signe associé : L'Eau\n");
    }else if((mois_maintenant==3&&jour_maintenant>=21)||(mois_maintenant==4&&jour_maintenant<=20)) {
	printf("Nous sommes dans la période du Bélier, signe associé : Le Feu\n");
    }else if((mois_maintenant==4&&jour_maintenant>=21)||(mois_maintenant==5&&jour_maintenant<=21)) {
	printf("Nous sommes dans la période du Taureau, signe associé : La Terre\n");
    }else if((mois_maintenant==5&&jour_maintenant>=22)||(mois_maintenant==6&&jour_maintenant<=21)) {
	printf("Nous sommes dans la période des Gémeaux, signe associé : L'Air\n");
    }else if((mois_maintenant==6&&jour_maintenant>=22)||(mois_maintenant==7&&jour_maintenant<=22)) {
	printf("Nous sommes dans la période des Cancers, signe associé : L'Eau\n");
    }else if((mois_maintenant==7&&jour_maintenant>=23)||(mois_maintenant==8&&jour_maintenant<=22)) {
	printf("Nous sommes dans la période du Lion, signe associé : Le Feu \n");
    }else if((mois_maintenant==8&&jour_maintenant>=23)||(mois_maintenant==9&&jour_maintenant<=22)) {
	printf("Nous sommes dans la période de la Vierge, signe associé : La Terre\n");
    }else if((mois_maintenant==9&&jour_maintenant>=23)||(mois_maintenant==10&&jour_maintenant<=22)) {
	printf("Nous sommes dans la période de la Balance, signe associé : L'Air\n");
    }else if((mois_maintenant==10&&jour_maintenant>=23)||(mois_maintenant==11&&jour_maintenant<=22)) {
	printf("Nous sommes dans la période du Scorpion, signe associé : L'Eau\n");
    }else if((mois_maintenant==11&&jour_maintenant>=23)||(mois_maintenant==12&&jour_maintenant<=21)) {
	printf("Nous sommes dans la période du Sagittaire, signe associé : Le Feu\n");
    }else if((mois_maintenant==12&&jour_maintenant>=22)||(mois_maintenant==1&&jour_maintenant<=20)) {
	printf("Nous sommes dans la période du Capricorne, signe associé : La Terre\n");
    }
    
    if(mois_maintenant==12 && jour_maintenant<26) {
	if(heure_maintenant<12) {
	    noel=26-jour_maintenant;
	    printf("Vous avez encore %d chocolats à manger dans votre calendrier de l'avant !\n",noel);
	}else if(heure_maintenant>12) {
	    noel=25-jour_maintenant;
	    printf("Vous avez encore %d chocolats à manger dans votre calendrier de l'avant !\n",noel);
	}
    }
    printf("\n") ;

    rc = scanf("%d\n", &n);
    if(rc != 1) {
        fprintf(stderr, "N'a pas pu lire le nombre de rendez-vous.\n");
        exit(1);
    }

    if(n < 0 || n > 5000) {
        fprintf(stderr, "Vous avez %d rendez-vous ?", n);
        exit(1);
    }
    min_actuel = min_maintenant + heure_maintenant*60 ;
    printf("Rendez-vous dans les 24h\n") ;

    for(i = 0; i < n; i++) {
        rc = scanf("%d,%d,%d,%d,%d,%511[^\n]\n",
                   &annee, &mois, &jour, &heure, &min, intitule);
        if(rc != 6) {
            fprintf(stderr, "Échec de lecture.\n");
            exit(1);
	}
	
	if((annee%400==0) || (annee%4==0 && annee%100!=0)){
	    bissextile=1;
	}else{
	    bissextile=0;
	}
	
	if(mois>12 || mois<1) {
	    printf("Erreur de mois dans le rendez vous %d\n",i);
	}else if((mois==1 || mois==3 || mois==5 || mois==7 || mois==8 || mois==10 || mois==12) && (jour>31)){
	    printf("Jour inexistant pour le mois donné dans le rendez-vous %d\n",i+1);
	}else if((mois==4 || mois==6 || mois==9 || mois==11) && (jour>30)){
	    printf("Jour inexistant pour le mois donné dans le rendez-vous %d\n",i+1);
	}else if(mois==2 && bissextile==1 && jour>29){
	    printf("Jour inexistant pour le mois donné dans le rendez-vous %d\n",i+1);
	}else if(mois==2 && bissextile==0 && jour>28){
	    printf("Jour inexistant pour l'année du rendez-vous %d\n",i+1);
	}
	
	min_rdv = min + heure*60 ;
	
	if(annee==annee_maintenant && mois==mois_maintenant) {
	    if(jour==jour_maintenant && min_rdv>min_actuel && min_rdv<min_journee ){
		rdv_jour =rdv_jour+1;
		timer= min_rdv-min_actuel;
		timer2=timer/60;
		timer3=timer%60;
		printf("     Aujourd'hui à %02dh%02d - %s \n      aura lieu dans %dh%02d\n", heure, min, intitule,timer2,timer3);
	    }else if(jour==jour_maintenant+1 && min_rdv<min_actuel && min_rdv>=0) {
		rdv_jour=rdv_jour+1;
		timer=(min_journee-min_actuel)+min_rdv;
		timer2=timer/60;
		timer3=timer%60;
		printf("      Demain à %02dh%02d - %s \n      aura lieu dans %dh%02d\n", heure, min, intitule,timer2,timer3);
	    }
	}else if(annee==annee_maintenant){
	    if(mois==mois_maintenant+1&&(mois_maintenant==1||mois_maintenant==3||mois_maintenant==5||mois_maintenant==7||mois_maintenant==8||mois_maintenant==10||mois_maintenant==12)&&jour_maintenant==31&&jour==1&& min_rdv<min_actuel && min_rdv>=0){
		rdv_jour=rdv_jour+1;
		timer=(min_journee-min_actuel)+min_rdv;
		timer2=timer/60;
		timer3=timer%60;
		printf("      Demain à %02dh%02d - %s \n      aura lieu dans %dh%02d\n", heure, min, intitule,timer2,timer3);
	    }else if(mois==mois_maintenant+1&&(mois_maintenant==4||mois_maintenant==6||mois_maintenant==9||mois_maintenant==11)&&jour_maintenant==30&&jour==1&& min_rdv<min_actuel && min_rdv>=0){
		rdv_jour=rdv_jour+1;
		timer=(min_journee-min_actuel)+min_rdv;
		timer2=timer/60;
		timer3=timer%60;
		printf("      Demain à %02dh%02d - %s \n      aura lieu dans %dh%02d\n", heure, min, intitule,timer2,timer3);
	    }else if(mois==mois_maintenant+1&&mois_maintenant==2&&bissextile==1&&jour_maintenant==29&&jour==1&& min_rdv<min_actuel && min_rdv>=0){
		rdv_jour=rdv_jour+1;
		timer=(min_journee-min_actuel)+min_rdv;
		timer2=timer/60;
		timer3=timer%60;
		printf("      Demain à %02dh%02d - %s \n      aura lieu dans %dh%02d\n", heure, min, intitule,timer2,timer3);
	    }else if(mois==mois_maintenant+1&&mois_maintenant==2&&bissextile==0&&jour_maintenant==28&&jour==1&& min_rdv<min_actuel && min_rdv>=0){
		rdv_jour=rdv_jour+1;
		timer=(min_journee-min_actuel)+min_rdv;
		timer2=timer/60;
		timer3=timer%60;
		printf("      Demain à %02dh%02d - %s \n      aura lieu dans %dh%02d\n", heure, min, intitule,timer2,timer3);
	    }
	}else if(annee==annee_maintenant+1&&mois==1&&jour==1&& min_rdv<min_actuel && min_rdv>=0){
	    rdv_jour=rdv_jour+1;
	    timer=(min_journee-min_actuel)+min_rdv;
	    timer2=timer/60;
	    timer3=timer%60;
	    printf("      Demain à %02dh%02d - %s \n      aura lieu dans %dh%02d\n", heure, min, intitule,timer2,timer3);
	}
	
	if(heure>=8 && heure<=11) {
	    rdv_matin = rdv_matin+1 ;
	}else if(heure>=12 && heure<=18) {
	    rdv_aprem = rdv_aprem+1;
	}else if(heure>=19 && heure <=22) {
	    rdv_soir=rdv_soir+1;
	}else if(heure==23 || heure<=7) {
	    rdv_nuit=rdv_nuit+1;
	}
	if(annee>annee_maintenant ||(annee==annee_maintenant && mois>mois_maintenant) || (annee==annee_maintenant && mois==mois_maintenant && jour>jour_maintenant) ||(annee==annee_maintenant && mois==mois_maintenant && jour==jour_maintenant && heure>heure_maintenant) ||(annee==annee_maintenant && mois==mois_maintenant && jour==jour_maintenant && heure==heure_maintenant && min>min_maintenant)) {
	    rdv_futur=rdv_futur+1 ;
	}else if(annee<annee_maintenant ||(annee==annee_maintenant && mois<mois_maintenant) ||(annee==annee_maintenant && mois==mois_maintenant && jour<jour_maintenant) ||(annee==annee_maintenant && mois==mois_maintenant && jour==jour_maintenant && heure<heure_maintenant) ||(annee==annee_maintenant && mois==mois_maintenant && jour==jour_maintenant && heure==heure_maintenant && min<min_maintenant)) {
	    rdv_passe=rdv_passe+1;
	}
    }
    
    printf("\n");
    if(rdv_matin>0) {
	printf("Rendez-vous le matin : %d\n", rdv_matin) ;
    }else{
	printf("Aucun rendez-vous le matin.\n");
    }
    if(rdv_aprem>0) {
	printf("Rendez-vous l'après-midi : %d\n",rdv_aprem);
    }else{
	printf("Aucun rendez-vous l'après-midi.\n");
    }
    if(rdv_soir>0) {
	printf("Rendez-vous le soir : %d\n",rdv_soir);
    }else{
	printf("Aucun rendez-vous le soir.\n");
    }
    if(rdv_nuit>0) {
	printf("Rendez-vous la nuit : %d\n",rdv_nuit);
    }else{
	printf("Aucun rendez-vous la nuit.\n");
    }
    printf("\n");
    if(rdv_passe>0){
	printf("Rendez-vous dans le passé : %d\n", rdv_passe);
    }else{
	printf("Aucun rendez-vous dans le passé.\n");
    }
    if(rdv_jour>0){
	printf("Rendez-vous dans les 24h : %d\n", rdv_jour);
    }else{
	printf("Aucun rendez-vous dans les 24h.\n");
    }
    if(rdv_futur>0){
	printf("Rendez-vous dans le futur : %d\n", rdv_futur-rdv_jour);
    }else{
	printf("Aucun rendez-vous dans le futur.\n");
    }
    return 0;
}
