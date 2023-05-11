
#include "gen/GetIonoBdgimAlpha.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoBdgimAlpha
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoBdgimAlpha::CmdName = "GetIonoBdgimAlpha";
    const char* const GetIonoBdgimAlpha::Documentation = "Get the BeiDou (BDGIM) ionospheric Alpha coefficient (in TECu)";

    REGISTER_COMMAND_FACTORY(GetIonoBdgimAlpha);


    GetIonoBdgimAlpha::GetIonoBdgimAlpha()
      : CommandBase(CmdName)
    {}

    GetIonoBdgimAlpha::GetIonoBdgimAlpha(int index)
      : CommandBase(CmdName)
    {

      setIndex(index);
    }

    GetIonoBdgimAlphaPtr GetIonoBdgimAlpha::create(int index)
    {
      return std::make_shared<GetIonoBdgimAlpha>(index);
    }

    GetIonoBdgimAlphaPtr GetIonoBdgimAlpha::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoBdgimAlpha>(ptr);
    }

    bool GetIonoBdgimAlpha::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
        ;

    }

    std::string GetIonoBdgimAlpha::documentation() const { return Documentation; }


    int GetIonoBdgimAlpha::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetIonoBdgimAlpha::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetIonoBdgimAlpha::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
