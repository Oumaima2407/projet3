#include<stdio.h>
#include<string.h>
//declaration des structures
typedef struct {
        int jour,mois,annee;
} date; 
typedef struct{
	char refproduit[150],nom[150];
	float prix;
}produit;
typedef struct {
 	char refvendeur[150];
 	char nom[150],prenom[150]; 
}vendeur;  
 typedef struct {
 	char refclient[150];
 	produit produit_achete[1500];
 	date datedenaissance;
}client; 

	//declaration des variables.

 	int choix,nb_p,nbd_p,i,j,deja,tr,prod_a_mod,prod_a_supp,prod_a_aff,w,h;
 	int vend_a_mod,vend_a_supp,vend_a_aff,nb_v,nbd_v;
 	int cli_a_mod,cli_a_supp,cli_a_aff,nb_c,nbd_c,g,o;
 	char ref_p[150],ref_v[150],ref_c[150],ref_pa[150];
 	int z,t,nb_pa[1500],ou;
 	int oui,fin;
 	produit p[1500];
 	vendeur v[1500];
 	client c[1500];
 	int A=0;


main() {


	nbd_p=0;//initialisation du nombre totale que j'ai de produits
	nbd_v=0;//initialisation du nombre totale que j'ai de vendeurs
	nbd_c=0;//initialisation du nombre totale que j'ai de clients
		printf("************************DEBUT DU PROGRAMME************************\n\n\n");
 	//affichage du menu
printf("-------------MENU-------------\n");	
printf("1- Ajouter un Produit \n\n2- Modifier un Produit \n\n3- Supprimer un Produit \n\n4- Afficher un Produit \n\n5- Ajouter un Vendeur \n\n6- Modifier un Vendeur \n\n7- Supprimer un Vendeur \n\n8- Afficher un Vendeur \n\n9- Ajouter un Client \n\n10- Modifier un Client \n\n11- Supprimer un Client \n\n12- Afficher un Client \n\n13-Quitter le programme");
printf("\n-------------------------------\n");
do{
	do{
	
	printf("\n\n////////Entrer votre choix du menu qui precede//////// \n");
	scanf("%d",&choix);
	if(choix<1||choix>13)
	{
		printf("veuiller enter un choix valide");
	}
	
	}while(choix<1||choix>13);




switch(choix){
	case 1:{
		//l'ajout des produits
		do{	if(nbd_p==1500)
		{
			printf("mémoire pleine pour ajouter un produit il faut supprimer un autre\n");
		}
		else{
		
			
		if(nbd_p>1500)
		{nbd_p=nbd_p-nb_p;//si on a depasse la taille max du tableau je retranche la dernier valeur de nb de produit a ajoute
		}
	
		printf("Combien de produits souhaitez vous ajouter ");
		scanf("%d",&nb_p);
		nbd_p=nbd_p+nb_p;//Pour avoir le nombre totale de produit qu'on a dans le tableau
		}}while(nb_p<1||nbd_p>1500);
		
		for(i=nbd_p-nb_p;i<nbd_p;i++){
			if(i==0){
			fflush(stdin);
			printf("entrer la reference du produit %d: ",i+1);
			gets(p[i].refproduit);}
			else{
			do{
			deja=0;
			fflush(stdin);
			printf("entrer la reference du produit %d: ",i+1);
			gets(p[i].refproduit);
			for(j=0;j<i;j++)
			{
				if(strcmp(p[i].refproduit,p[j].refproduit)==0)
				{
					deja=1;
				}
			}
				}while(deja==1);
				
			}
		    printf("entrer le nom du produit %d: ",i+1);
			gets(p[i].nom);
			printf("entrer le prix du produit %d: ",i+1);
			scanf("%f",&p[i].prix);
		}
		
		
		
		
		
		}
		break;
	
	case 2: {
		//la modification des produits
	if(nbd_p==0)
	{
		printf("\nPas de produit a modifier\nVeuiller entrer un produit d'abord en appuyant sur la touche 1\n ");
	}
	else{
	
	
	
	do {
	
	fflush(stdin);
		printf("\nentre la referance du produit a modifier ");
		gets(ref_p);
		for(i=0,tr=0;i<nbd_p;i++)
		{  
			if(strcmp (ref_p,p[i].refproduit)==0)
			{
			prod_a_mod=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas de produit de reference %s",ref_p);
		}       }while(tr==0);
		if(tr==1)
		{do{
			deja=0;
			fflush(stdin);
			printf("entrer la nouvelle reference du produit %d: ",prod_a_mod+1);
			gets(p[prod_a_mod].refproduit);
			for(j=0,w=0;j<nbd_p;j++)
			{
				if(strcmp(p[prod_a_mod].refproduit,p[j].refproduit)==0)
				{    w++;/* pour qu'il ne se compare pas a lui meme*/
					if(w==2)
					{
					deja=1;
			      	} 
				}
			}
				}while(deja==1);		
		
		printf("entrer le nouveau nom du produit %d: ",prod_a_mod+1);
		gets(p[prod_a_mod].nom);
		printf("entrer le nouveau prix du produit %d: ",prod_a_mod+1);
		scanf("%f",&p[prod_a_mod].prix);
		}}
		
		break;
	}
	case 3: {
		//le suppression des produits
	if(nbd_p==0)
	{
		printf("\nPas de proquit a supprimer\nVeuiller entrer un produit d'abord en appuyant sur la touche 1\n ");
	}
	else{
	
	
	 do{
		
	
		fflush(stdin);
		printf("\nentre la reference du produit a supprimer ");
		gets(ref_p);
		for(i=0,tr=0;i<nbd_p;i++)
		{
			if(strcmp(ref_p,p[i].refproduit)==0){
			
			prod_a_supp=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas de produit de reference %s",ref_p);
		}}while(tr==0);
		if(tr==1){
			printf("Etes vous sur de vouloir supprimer le produit de ref %s?\nSi oui appuyer sur la touche 1 sinon appuyer sur un aute chiffre",ref_p);
			scanf("%d",&oui);
			if(oui==1){
			
			for(h=prod_a_supp;h<nbd_p-1;h++)
			{
				p[h]=p[h+1];
			}
			nbd_p=nbd_p-1;
			printf("\nLe produit de reference %s a ete supprimer",ref_p);
			}
		}}
		
		break;
	}	
	case 4: { 
	//l'affichage des produits
	if(nbd_p==0)
	{
		printf("\nPas de produit a afficher\nVeuiller entrer un produit d'abord en appuyant sur la touche 1\n ");
	}
	else{
	do{
		
	
		fflush(stdin);
		printf("\nentre la reference du produit a afficher ");
		gets(ref_p);
		for(i=0,tr=0;i<nbd_p;i++)
		{
			if(strcmp(ref_p,p[i].refproduit)==0){
			
			prod_a_aff=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas de produit de reference %s",ref_p);
		}}while(tr==0);
		if(tr==1){
			printf("\n\nla reference du produit est: %s",p[prod_a_aff].refproduit);
			printf("\nle nom du produit est :%s",p[prod_a_aff].nom);
			printf("\nle prix du produit est: %.3f\n",p[prod_a_aff].prix);
		}}
		
		break;
	}
	
	
	case 5:{
		//l'ajout des vendeurs
		do{	if(nbd_v==1500)
		{
			printf("mémoire pleine pour ajouter un vendeur il faut supprimer un autre\n");
		}
		else{
		
			
		if(nbd_v>1500)
		{nbd_v=nbd_v-nb_v;//si on a depasse la taille max du tableau je retranche la dernier valeur de nb de vendeur a ajoute
		}
	
		printf("Combien de vendeurs souhaitez vous ajouter ");
		scanf("%d",&nb_v);
		nbd_v=nbd_v+nb_v;//Pour avoir le nombre totale de vendeur qu'on a dans le tableau
		}}while(nb_v<1||nbd_v>1500);
		
		for(i=nbd_v-nb_v;i<nbd_v;i++){
			if(i==0){
			fflush(stdin);
			printf("entrer la reference du vendeur %d: ",i+1);
			gets(v[i].refvendeur);}
			else{
			do{
			deja=0;
			fflush(stdin);
			printf("entrer la reference du vendeur %d: ",i+1);
			gets(v[i].refvendeur);
			for(j=0;j<i;j++)
			{
				if(strcmp(v[i].refvendeur,v[j].refvendeur)==0)
				{
					deja=1;
				}
			}
				}while(deja==1);
				
			}
		    printf("entrer le nom du vendeur %d: ",i+1);
			gets(v[i].nom);
			printf("entrer le prenom du vendeur %d: ",i+1);
			gets(v[i].prenom);
		}
		
		
		
		
		
		}
		break;
	
	case 6: {
		//la modification des vendeurs
	if(nbd_v==0)
	{
		printf("\nPas de vendeur a modifier\nVeuiller entrer un vendeur d'abord en appuyant sur la touche 5\n ");
	}
	else{
	
	
	
	do {
	
	fflush(stdin);
		printf("\nentre la reference du vendeur a modifier ");
		gets(ref_v);
		for(i=0,tr=0;i<nbd_v;i++)
		{  
			if(strcmp (ref_v,v[i].refvendeur)==0)
			{
			vend_a_mod=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas un vendeur de reference %s",ref_v);
		}       }while(tr==0);
		if(tr==1)
		{do{
			deja=0;
			fflush(stdin);
			printf("entrer la nouvelle reference du vendeur %d: ",vend_a_mod+1);
			gets(v[vend_a_mod].refvendeur);
			for(j=0,w=0;j<nbd_v;j++)
			{
				if(strcmp(v[vend_a_mod].refvendeur,v[j].refvendeur)==0)
				{    w++;/* bach may9arnouch m3a rassou ou deja twli 1*/
					if(w==2)
					{
					deja=1;
			      	} 
				}
			}
				}while(deja==1);		
		
		printf("entrer le nouveau nom du vendeur %d: ",prod_a_mod+1);
		gets(v[vend_a_mod].nom);
		printf("entrer le nouveau prenom du vendeur %d: ",prod_a_mod+1);
		gets(v[vend_a_mod].prenom);
		}}
		
		break;
	}
	case 7: {
		//la suppression des vendeurs
	if(nbd_v==0)
	{
		printf("\nPas de vendeur a supprimer\nVeuiller entrer un vendeur d'abord en appuyant sur la touche 5\n ");
	}
	else{
	
	
	 do{
		
	
		fflush(stdin);
		printf("\nentre la reference du vendeur a supprimer ");
		gets(ref_v);
		tr=0;
		for(i=0;i<nbd_v;i++)
		{
			if(strcmp(ref_v,v[i].refvendeur)==0){
			
			vend_a_supp=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas un vendeur de reference %s",ref_v);
		}}while(tr==0);
		if(tr==1){
			printf("Etes vous sur de vouloir supprimer le vendeur de ref %s?\nSi oui appuyer sur la touche 1 sinon appuyer sur un aute chiffre",ref_v);
			scanf("%d",&oui);
			if(oui==1){
			for(h=vend_a_supp;h<nbd_v-1;h++)
			{
				v[h]=v[h+1];
			}
			nbd_v=nbd_v-1;
			printf("\nLe vendeur de reference %s a ete supprimer",ref_v);
			}
		}}
		
		break;
	}	
	case 8: { 
	//l'affichage des vendeurs
	if(nbd_v==0)
	{
		printf("\n Pas de vendeur a afficher\nVeuiller entrer un vendeur d'abord en appuyant sur la touche 5\n ");
	}
	else{
	do{
		
	
		fflush(stdin);
		printf("\nentre la reference du vendeur a afficher ");
		gets(ref_v);
		for(i=0,tr=0;i<nbd_v;i++)
		{
			if(strcmp(ref_v,v[i].refvendeur)==0){
			
			vend_a_aff=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas un vendeur de reference %s",ref_v);
		}}while(tr==0);
		if(tr==1){
			printf("\n\nla reference du vendeur est: %s",v[vend_a_aff].refvendeur);
			printf("\nle nom du vendeur est: %s",v[vend_a_aff].nom);
			printf("\nle prenom du vendeur est: %s\n",v[vend_a_aff].prenom);
		}}
		
		break;
	}
		case 9:{
			//l'ajout des clients
		
		 if(nbd_p==0)
		{
			printf("\nVeuiller entrer un produit d'abord en appuyant sur la touche 1 ");
		}
		else
		{
		
		
		do{	if(nbd_c==1500)
		{
			printf("\nmémoire pleine pour ajouter un client il faut supprimer un autre\n");
		}
		else{
		
			
		if(nbd_c>1500)
		{nbd_c=nbd_c-nb_c;//si on a depasse la taille max du tableau je retranche la dernier valeur de nb de client a ajoute
		}
	
		printf("Combien de clients souhaitez vous ajouter ");
		scanf("%d",&nb_c);
		nbd_c=nbd_c+nb_c;//Pour avoir le nombre totale de client qu'on a dans le tableau
		}}while(nb_c<1||nbd_c>1500);
		
		for(i=nbd_c-nb_c;i<nbd_c;i++){
			if(i==0){
			fflush(stdin);
			printf("entrer la reference du client %d: ",i+1);
			gets(c[i].refclient);}
			else{
			do{
			deja=0;
			fflush(stdin);
			printf("entrer la reference du client %d: ",i+1);
			gets(c[i].refclient);
			for(j=0;j<i;j++)
			{
				if(strcmp(c[i].refclient,c[j].refclient)==0)
				{
					deja=1;
				} 
			}
				}while(deja==1);
				
			}
			do{
			A++;
			if(A>1)
			printf("la date est fausse\n");
		    printf("entrer la date de naissance (jour mois annee) du client %d: ",i+1);
			scanf("%d%d%d",&c[i].datedenaissance.jour,&c[i].datedenaissance.mois,&c[i].datedenaissance.annee);
		
			}while(((c[i].datedenaissance.jour)<=0)||((c[i].datedenaissance.annee)<=0||(c[i].datedenaissance.annee)>2020)||((c[i].datedenaissance.mois)<=0||(c[i].datedenaissance.mois)>12)||(((c[i].datedenaissance.mois)==1||(c[i].datedenaissance.mois)==3||(c[i].datedenaissance.mois)==5||(c[i].datedenaissance.mois)==7||(c[i].datedenaissance.mois)==8||(c[i].datedenaissance.mois)==10||(c[i].datedenaissance.mois)==12)&&(c[i].datedenaissance.jour)>31)||(((c[i].datedenaissance.mois)==4||(c[i].datedenaissance.mois)==6||(c[i].datedenaissance.mois)==9||(c[i].datedenaissance.mois)==11)&&(c[i].datedenaissance.jour)>30)||(((c[i].datedenaissance.annee)%400==0||((c[i].datedenaissance.annee)%4==0&&(c[i].datedenaissance.annee)%100!=0))&&(c[i].datedenaissance.mois)==2&&(c[i].datedenaissance.jour)>29)||(!((c[i].datedenaissance.annee)%400==0||((c[i].datedenaissance.annee)%4==0&&(c[i].datedenaissance.annee)%100!=0))&&(c[i].datedenaissance.mois)==2&&(c[i].datedenaissance.jour)>28));
			
			printf("Les produits achetes par le client de reference %s :\n\n",c[i].refclient);
		    o=0;t=0;
			do{	fflush(stdin);
				printf("entrer le reference du produit %d\n",o+1);
				gets(ref_pa);
				tr=0;
				for(g=0;g<nbd_p;g++)
				{
					if(strcmp (ref_pa,p[g].refproduit)==0)
					{
						
						c[i].produit_achete[o]=p[g];
						o++;tr=1;
						printf("pour ajouter un autre produit appuyer sur 0 sinon appuyer sur 1");
				        scanf("%d",&t);
					}
				}
				if(tr==0)
				{
					printf("le produit de reference %s n'existe pas parmi les produits du magasin\n",ref_pa);
				}
				
				
			}while(t==0);
			nb_pa[i]=o;

		}}
		
		
		
		
		
		
		break;
    }
    case 10: {
    	//la modification des clients
	if(nbd_c==0)
	{
		printf("\nPas de client a modifier\nVeuiller entrer un client d'abord en appuyant sur la touche 9\n ");
	}
	else{
	
	
	
	do {
	
	fflush(stdin);
		printf("\nentre la reference du client a modifier ");
		gets(ref_c);
		for(i=0,tr=0;i<nbd_c;i++)
		{  
			if(strcmp (ref_c,c[i].refclient)==0)
			{
			cli_a_mod=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas de client de reference %s",ref_c);
		}       }while(tr==0);
		if(tr==1)
		{do{
			deja=0;
			fflush(stdin);
			printf("entrer la nouvelle reference du client %d: ",cli_a_mod+1);
			gets(c[cli_a_mod].refclient);
			for(j=0,w=0;j<nbd_p;j++)
			{
				if(strcmp(c[cli_a_mod].refclient,c[j].refclient)==0)
				{    w++;/* bach may9arnouch m3a rassou ou deja twli 1*/
					if(w==2)
					{
					deja=1;
			      	} 
				}
			}
				}while(deja==1);		
		
		printf("entrer la nouvelle date de naissance du client %d: ",cli_a_mod+1);
		scanf("%d%d%d",&c[cli_a_mod].datedenaissance.jour,&c[cli_a_mod].datedenaissance.mois,&c[cli_a_mod].datedenaissance.annee);
		
	    printf("modifier les produit acheter par le client de reference %s :\n\n",c[i].refclient);
		    o=0;t=0;
			do{	fflush(stdin);
				printf("entrer le reference du produit %d\n",o+1);
				gets(ref_pa);
				tr=0;
				for(g=0;g<nbd_p;g++)
				{
					if(strcmp (ref_pa,p[g].refproduit)==0)
					{
						//pa[o]=p[g];
						c[cli_a_mod].produit_achete[o]=p[g];
						o++;tr=1;
						printf("pour ajouter un autre produit appuyer sur 0 sinon appuyer sur 1");
				        scanf("%d",&t);
					}
				}
				if(tr==0)
				{
					printf("le produit de reference %s n'existe pas parmi les produits du magasin\n",ref_pa);
				}
				
				
			}while(t==0);
		}}
		
		break;
	}
		case 11: {
			//le suppression des clients
	if(nbd_c==0)
	{
		printf("\nPas de clients a supprimer\nVeuiller entrer un client d'abord en appuyant sur la touche 9\n ");
	}
	else{
	
	
	 do{
		
	
		fflush(stdin);
		printf("\nentre la reference du client a supprimer ");
		gets(ref_c);
		for(i=0,tr=0;i<nbd_c;i++)
		{
			if(strcmp(ref_c,c[i].refclient)==0){
			
			cli_a_supp=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas de client de reference %s",ref_c);
		}}while(tr==0);
		if(tr==1){
			printf("Etes vous sur de vouloir supprimer le client de ref %s?\nSi oui appuyer sur la touche 1 sinon appuyer sur un aute chiffre",ref_c);
			scanf("%d",&oui);
			if(oui==1){
			for(h=cli_a_supp;h<nbd_c-1;h++)
			{
				c[h]=c[h+1];
			}
			nbd_c=nbd_c-1;
			printf("\nLe client de reference %s a ete supprimer",ref_c);
		}
		}}
		
		break;
	}
	
	case 12: { 
	//l'affichage des clients
	if(nbd_c==0)
	{
		printf("\nPas de client a afficher\nVeuiller entrer un client d'abord en appuyant sur la touche 9\n ");
	}
	else{
	do{
		
	
		fflush(stdin);
		printf("\nentre la reference du client a afficher ");
		gets(ref_c);
		for(i=0,tr=0;i<nbd_c;i++)
		{
			if(strcmp(ref_c,c[i].refclient)==0){
			
			cli_a_aff=i;
			tr=1;}
		}
		
		if(tr==0)
		{
			printf("\nil n'existe pas de client de reference %s",ref_c);
		}}while(tr==0);
		if(tr==1){
			printf("\n\nla reference du client est :%s",c[cli_a_aff].refclient);
		
			
			printf("\nla date de naissance du client est: %d/%d/%d",c[cli_a_aff].datedenaissance.jour,c[cli_a_aff].datedenaissance.mois,c[cli_a_aff].datedenaissance.annee);
			
			printf("\nles produits achetter par le client sont:");
			for(ou=0;ou<nb_pa[cli_a_aff];ou++)
			{
				printf("\nporduit %d :\n",ou+1);
				printf("\n  -reference: %s",c[cli_a_aff].produit_achete[ou].refproduit);
			    printf("\n  -nom: %s",c[cli_a_aff].produit_achete[ou].nom);
			    printf("\n  -prix %.3f",c[cli_a_aff].produit_achete[ou].prix);
			}
		}}
		
		break;
	}
	
	case 13:{
		printf("Etes vous sur de vouloir sortir du programme?  \nSi oui appuyer sur la touche 1 Si non appuyer sur un autre chiffre");
		scanf("%d",&fin);
		if(fin==1)
		{
		
		printf("\n\n\n************************FIN DE PROGRAMME************************");
	    }
	    else{
	    	choix=1;
		}
		break;
	}
	 
	
	
	}
    

	
}while(choix!=13);  
}
		

	



