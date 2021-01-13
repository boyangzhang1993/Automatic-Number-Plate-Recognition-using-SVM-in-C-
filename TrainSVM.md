   # Train the SVM
    ## Generate svm smart pointer by Ptr<SVM> 
    Ptr<SVM> svm = SVM::create();
    ## Set Type, Knernel, and criteria
    svm->setType(SVM::C_SVC);
    svm->setKernel(SVM::LINEAR);
    svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
