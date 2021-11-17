#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouHealthInfoForSV.
    ///
    /// Name   Type Description
    /// ------ ---- -------------------------------------------------------------------------
    /// SvId   int  Satellite SV ID 1..35
    /// Health int  Health Info, 9-bit integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511
    ///

    class GetBeiDouHealthInfoForSVResult;
    typedef std::shared_ptr<GetBeiDouHealthInfoForSVResult> GetBeiDouHealthInfoForSVResultPtr;
    
    
    class GetBeiDouHealthInfoForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouHealthInfoForSVResult();

      GetBeiDouHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health);
  
      static GetBeiDouHealthInfoForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health);
      static GetBeiDouHealthInfoForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

