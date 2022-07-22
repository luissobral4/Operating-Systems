char* atRankaux (Palavras p, int k,int atual){
  char *palavra;
  if(p == NULL) || (p -> esq == NUll && p -> dir == NUll && atual != k))
    return NULL;

  if(k == atual)
    return p -> raiz;

  int pe,pd;
  if(p -> esq == NUll)
    pe = 0;
  else if(p -> dir == NUll)
    pd = 0;
  else{
    pe = (p->esq) -> quantos;
    pd = (p->dir) -> quantos;
  }


  if(k < atual + pe)
    palavra = atRankaux (p -> esq, k,atual + 1);
  else if(k < atual + pe + pd)
    palavra = atRankaux (p -> dir, k,atual + pe);
  else
    palavra = NULL;

  return palavra;
}

char* atRank (Palavras p, int k){
  return atRankaux(p,k,0);
}
