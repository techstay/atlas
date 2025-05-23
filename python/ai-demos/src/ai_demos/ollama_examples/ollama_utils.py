import ollama
import rich

#
# Ollama methods
#

# Listing models
models = ollama.list().models
rich.print([model.model for model in models])

# Show current model
ps_model = ollama.ps()
rich.print(ps_model)
