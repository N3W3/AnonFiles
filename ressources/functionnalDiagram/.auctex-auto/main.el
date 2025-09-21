;; -*- lexical-binding: t; -*-

(TeX-add-style-hook
 "main"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("tikz" "") ("draftwatermark" "")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "tikz"
    "draftwatermark"))
 :latex)

