FROM python:alpine
ADD main.py requirements.txt zomato-dataset.csv code/
WORKDIR /code
RUN pip install -r requirements.txt
CMD ["python", "main.py"]