#ifndef COMMAND_EXCEPTION_H__
#define COMMAND_EXCEPTION_H__

#include <exception>

#include "command_result.h"

namespace Sdx
{

class CommandException : public std::exception
{
public:
  explicit CommandException(CommandResultPtr cmdResult, const std::string& errorMsg);
  virtual ~CommandException() throw();

  virtual const char* what() const throw();
  CommandResultPtr result() const;

protected:
  CommandResultPtr m_cmdResult;
  std::string m_message;
};

} // namespace Sdx

#endif // COMMAND_EXCEPTION_H__