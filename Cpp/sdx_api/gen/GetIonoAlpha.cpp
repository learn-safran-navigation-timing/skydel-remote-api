
#include "GetIonoAlpha.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoAlpha
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoAlpha::CmdName = "GetIonoAlpha";
    const char* const GetIonoAlpha::Documentation = "Get the GPS ionospheric Alpha coefficient\n"
      "Alpha 0 is in seconds\n"
      "Alpha 1 is in seconds/semicircle\n"
      "Alpha 2 is in seconds/semicircle^2\n"
      "Alpha 3 is in seconds/semicircle^3\n"
      "\n"
      "Name  Type Description\n"
      "----- ---- ------------------------\n"
      "Index int  Coefficient index [0..3]";
    const char* const GetIonoAlpha::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoAlpha);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoAlpha);


    GetIonoAlpha::GetIonoAlpha()
      : CommandBase(CmdName, TargetId)
    {}

    GetIonoAlpha::GetIonoAlpha(int index)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetIonoAlpha::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index"}; 
      return names; 
    }


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
