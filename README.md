# Large Language Model assisted Transformation of Software Variants into a Software Product Line

[![Paper](https://img.shields.io/badge/paper-IEEE%20Xplore-blue.svg)](https://ieeexplore.ieee.org/document/11024511)
[![Conference](https://img.shields.io/badge/conference-ICSR%202025-red.svg)](https://conf.researchr.org/home/icsr-2025)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Abstract
Software systems often evolve into multiple variants to meet diverse requirements. This is usually achieved with the clone-and-own approach, where an existing variant is copied and modified. While efficient in the short term, this approach presents challenges for long-term maintenance. A suitable solution to overcome this, is to re-engineer the variants into a software product line (SPL). However, this process is labor-intensive and prone to errors. Although initial studies explore the use of large language models (LLMs) to assist in the re-engineering tasks, they do not address challenges such as hallucination and limited context windows, which restricts the applicability.In this paper, we present a novel approach to assist the transformation of cloned software variants into an SPL using an LLM. To mitigate hallucination, we propose a self-refinement feedback loop to validate the generated SPL. Additionally, we introduce a variation point filtering technique that reduces the input size, while preserving essential information. To quantify and evaluate the generated output, we propose the use of existing metrics that can be employed for the evaluation. Our evaluation demonstrates the effectiveness of the self-refinement feedback loop and variation point filtering based on an existing case study. The results, benchmarked against the proposed variability metrics, indicate that the generated SPL maintains equivalent complexity and potential for reusability, to the system it is compared against.

## 📁 Repository Structure

1. [`prompt-templates`](prompt-templates) The prompt templates used for the experiments.
2. [`spled_cloned-variants`](spled_cloned-variants) The cloned variants used as a case study.


## 📖 Citation
If you find our work useful, please cite:

```bibtex
@inproceedings{stumpfle2025large,
  title={Large Language Model assisted Transformation of Software Variants into a Software Product Line},
  author={St{\"u}mpfle, Johannes and Atray, Devansh and Jazdi, Nasser and Weyrich, Michael},
  booktitle={2025 IEEE/ACM 22nd International Conference on Software and Systems Reuse (ICSR)},
  pages={12--20},
  year={2025},
  organization={IEEE}
}
```

## 🙏 Acknowledgments

The evaluation of this work builds upon the excellent foundation provided by:

[SPLed](https://github.com/avengineers/SPLed) by AVENGINEERS (Licensed under MIT License)


## 📞 Contact

For questions or collaboration opportunities, please contact me: johannes.stuempfle@ias.uni-stuttgart.de

