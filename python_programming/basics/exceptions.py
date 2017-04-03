class MyError(Exception):
    pass

class MylistError(MyError):
    def __init__(self, expression, message):
        self.expression_error = expression
        self.message = message
