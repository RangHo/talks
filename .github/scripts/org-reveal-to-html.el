;;; org-reveal-to-html.el --- Build HTML presentations with Org-re-reveal

;; Copyright (C) 2024 RangHo Lee

;; Author: RangHo Lee <hello@rangho.me>

;;; Commentary:

;; This script is used to build HTML presentations with Org-re-reveal.  It is
;; intended to be used as a command line script.  To use it, run:
;;
;;     emacs --script build-org-reveal.el input.org
;;
;; This will take the Org file \"input.org\" and build it into an HTML file
;; \"output.html\".

(require 'package)

(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/") t)

(package-initialize)

(dolist (package '(org-re-reveal org-re-reveal-citeproc))
  (package-install package))

(require 'org-re-reveal)
(require 'org-re-reveal-citeproc)

(setq org-re-reveal-root "https://cdn.jsdelivr.net/npm/reveal.js@4"
      org-re-reveal-revealjs-version "4")

(add-to-list 'org-export-filter-paragraph-functions #'org-re-reveal-citeproc-filter-cite)

(let ((input-file (nth 0 command-line-args-left)))
  (with-temp-buffer
    (insert-file-contents input-file)
    (org-re-reveal-export-to-html)))
