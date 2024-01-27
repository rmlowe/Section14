.PHONY: clean All

All:
	@echo "----------Building project:[ Mystring-start - Debug ]----------"
	@cd "Mystring-start" && "$(MAKE)" -f  "Mystring-start.mk"
clean:
	@echo "----------Cleaning project:[ Mystring-start - Debug ]----------"
	@cd "Mystring-start" && "$(MAKE)" -f  "Mystring-start.mk" clean
