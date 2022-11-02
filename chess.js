// Função para realizar as jogas
$('#container div.row div').click(function(){
  
   // Captura o ID da posição da peça
   var id = $(this).attr('id');
  
   // Captura o conteudo da seleção (Imagem peça)
   var peca = $(this).text();
  
   // inclui a peça seleciona no WebStoraged utilizando a   função setPosicaoPeca. Caso a peça já esteja selecionada anteriormente, a mesma e posicionada no local desejada e é limpada do webStoraged
   if (peca != ""){
      setPosicaoPeca(id, peca);
      $(this).text("");
   }
   else {
      if (getPeca()){
         $('#'+id).text(getPeca());
        
            // Altera o contador de movimentos
            $('#pontuacao').text(
              parseInt($('#pontuacao').text()) + 1
            );
        
         // funcao para limpar os dados
         limparDados();
      }
   }
})

// Função para setar a posição da peça e salvar no webstoraged
function setPosicaoPeca(id, peca) {
  localStorage.setItem("id", id);
  localStorage.setItem("peca", peca);
}

// Função para retornar o ID da peça que havia sido selecionada anteriormente
function getPosicaoID() {
  return localStorage.getItem("id");
}

// Função para o retorno da peca selecionada anteriormente
function getPeca() {
  return localStorage.getItem('peca');
}

// Função para limpar todos os dados 
function limparDados() {
  localStorage.clear();
}

// Função para validar os dados da jogada
function validarJogada(posicaoInicial, posicaFinal, peca)
{
  // Cavalo preto
  if (peca == '&#9816') 
  {
    if (!(posicaoInicial - posicaFinal) == 17)
    {
      alert("Jogada Inválida");
    }
  }
}
