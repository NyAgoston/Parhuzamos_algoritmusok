 FILE *fp;
    fp = fopen("adatok.csv","w");
    fprintf(fp,"%d %lf \n%d %lf ",meret,time_spent_linear,meret,time_spent_rec);
    fclose(fp);