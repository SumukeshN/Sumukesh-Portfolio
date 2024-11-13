// JavaScript for smooth scrolling
document.addEventListener('DOMContentLoaded', function() {
    const links = document.querySelectorAll('nav ul li a');

    // Loop through each navigation link
    links.forEach(function(link) {
        link.addEventListener('click', function(e) {
            e.preventDefault();  // Prevent the default anchor behavior

            const targetId = this.getAttribute('href').substring(1);  // Get the target section id
            const targetSection = document.getElementById(targetId);  // Get the section element by id

            // Smooth scroll to the target section
            window.scrollTo({
                top: targetSection.offsetTop - 50,  // Adjusts for fixed navigation height
                behavior: 'smooth'
            });
        });
    });
});
