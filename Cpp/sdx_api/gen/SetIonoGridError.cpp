
#include "SetIonoGridError.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoGridError
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoGridError::CmdName = "SetIonoGridError";
    const char* const SetIonoGridError::Documentation = "Set the error offset for a ionospheric grid point\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ -------------------------------\n"
      "Band  int    The ionospheric grid band index\n"
      "Point int    The IGP index\n"
      "Error double The error offset at the IGP";
    const char* const SetIonoGridError::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIonoGridError);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIonoGridError);


    SetIonoGridError::SetIonoGridError()
      : CommandBase(CmdName, TargetId)
    {}

    SetIonoGridError::SetIonoGridError(int band, int point, double error)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setPoint(point);
      setError(error);
    }

    SetIonoGridErrorPtr SetIonoGridError::create(int band, int point, double error)
    {
      return std::make_shared<SetIonoGridError>(band, point, error);
    }

    SetIonoGridErrorPtr SetIonoGridError::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoGridError>(ptr);
    }

    bool SetIonoGridError::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
          && parse_json<double>::is_valid(m_values["Error"])
        ;

    }

    std::string SetIonoGridError::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIonoGridError::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Point", "Error"}; 
      return names; 
    }


    int SetIonoGridError::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIonoGridError::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void SetIonoGridError::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIonoGridError::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void SetIonoGridError::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIonoGridError::error() const
    {
      return parse_json<double>::parse(m_values["Error"]);
    }

    void SetIonoGridError::setError(double error)
    {
      m_values.AddMember("Error", parse_json<double>::format(error, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
