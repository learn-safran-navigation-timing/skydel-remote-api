
#include "GetIonoGridError.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridError
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridError::CmdName = "GetIonoGridError";
    const char* const GetIonoGridError::Documentation = "Get the error offset for a ionospheric grid point\n"
      "\n"
      "Name  Type Description\n"
      "----- ---- -------------------------------\n"
      "Band  int  The ionospheric grid band index\n"
      "Point int  The IGP index";
    const char* const GetIonoGridError::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridError);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridError);


    GetIonoGridError::GetIonoGridError()
      : CommandBase(CmdName, TargetId)
    {}

    GetIonoGridError::GetIonoGridError(int band, int point)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setPoint(point);
    }

    GetIonoGridErrorPtr GetIonoGridError::create(int band, int point)
    {
      return std::make_shared<GetIonoGridError>(band, point);
    }

    GetIonoGridErrorPtr GetIonoGridError::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridError>(ptr);
    }

    bool GetIonoGridError::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
        ;

    }

    std::string GetIonoGridError::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoGridError::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Point"}; 
      return names; 
    }


    int GetIonoGridError::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetIonoGridError::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void GetIonoGridError::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridError::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void GetIonoGridError::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
