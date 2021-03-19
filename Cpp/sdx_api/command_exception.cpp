#include "command_exception.h"

using namespace Sdx;

CommandException::CommandException(CommandResultPtr cmdResult, const std::string& errorMsg) :
  m_cmdResult(cmdResult)
{
  m_message = m_cmdResult->relatedCommand()->name() + " command failed => " + m_cmdResult->message() + errorMsg;
}

CommandException::~CommandException() throw (){}

const char* CommandException::what() const throw ()
{
  return m_message.c_str();
}

CommandResultPtr CommandException::result() const
{
  return m_cmdResult;
}