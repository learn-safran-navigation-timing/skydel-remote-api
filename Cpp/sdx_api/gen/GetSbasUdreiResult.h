#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasUdrei.
    ///
    /// Name  Type Description
    /// ----- ---- ---------------
    /// Udrei int  The UDREI value
    ///

    class GetSbasUdreiResult;
    typedef std::shared_ptr<GetSbasUdreiResult> GetSbasUdreiResultPtr;
    
    
    class GetSbasUdreiResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasUdreiResult();

      GetSbasUdreiResult(int udrei);

      GetSbasUdreiResult(CommandBasePtr relatedCommand, int udrei);

      static GetSbasUdreiResultPtr create(int udrei);

      static GetSbasUdreiResultPtr create(CommandBasePtr relatedCommand, int udrei);
      static GetSbasUdreiResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** udrei ****
      int udrei() const;
      void setUdrei(int udrei);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSbasUdreiResult);
  }
}

