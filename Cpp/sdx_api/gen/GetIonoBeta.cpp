
#include "gen/GetIonoBeta.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoBeta
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoBeta::CmdName = "GetIonoBeta";
    const char* const GetIonoBeta::Documentation = "Get the GPS ionospheric Beta coefficient\nBeta 0 is in seconds\nBeta 1 is in seconds/semicircle\nBeta 2 is in seconds/semicircle^2\nBeta 3 is in seconds/semicircle^3";

    REGISTER_COMMAND_FACTORY(GetIonoBeta);


    GetIonoBeta::GetIonoBeta()
      : CommandBase(CmdName)
    {}

    GetIonoBeta::GetIonoBeta(int index)
      : CommandBase(CmdName)
    {

      setIndex(index);
    }

    GetIonoBetaPtr GetIonoBeta::create(int index)
    {
      return std::make_shared<GetIonoBeta>(index);
    }

    GetIonoBetaPtr GetIonoBeta::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoBeta>(ptr);
    }

    bool GetIonoBeta::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
        ;

    }

    std::string GetIonoBeta::documentation() const { return Documentation; }


    int GetIonoBeta::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetIonoBeta::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetIonoBeta::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
