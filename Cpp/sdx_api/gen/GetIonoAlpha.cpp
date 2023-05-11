
#include "gen/GetIonoAlpha.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoAlpha
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoAlpha::CmdName = "GetIonoAlpha";
    const char* const GetIonoAlpha::Documentation = "Get the GPS ionospheric Alpha coefficient\nAlpha 0 is in seconds\nAlpha 1 is in seconds/semicircle\nAlpha 2 is in seconds/semicircle^2\nAlpha 3 is in seconds/semicircle^3";

    REGISTER_COMMAND_FACTORY(GetIonoAlpha);


    GetIonoAlpha::GetIonoAlpha()
      : CommandBase(CmdName)
    {}

    GetIonoAlpha::GetIonoAlpha(int index)
      : CommandBase(CmdName)
    {

      setIndex(index);
    }

    GetIonoAlphaPtr GetIonoAlpha::create(int index)
    {
      return std::make_shared<GetIonoAlpha>(index);
    }

    GetIonoAlphaPtr GetIonoAlpha::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoAlpha>(ptr);
    }

    bool GetIonoAlpha::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
        ;

    }

    std::string GetIonoAlpha::documentation() const { return Documentation; }


    int GetIonoAlpha::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetIonoAlpha::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetIonoAlpha::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
