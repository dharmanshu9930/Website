const container = document.querySelector('.container');
const signupBtn = document.querySelector('.green-bg button');

signupBtn.addEventListener('click', () => {
    container.classList.toggle('change');
})