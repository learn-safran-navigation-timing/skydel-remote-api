#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou CNav satellite health info
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..35
    ///

    class GetBeiDouCNavHealthInfoForSV;
    typedef std::shared_ptr<GetBeiDouCNavHealthInfoForSV> GetBeiDouCNavHealthInfoForSVPtr;
    
    
    class GetBeiDouCNavHealthInfoForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNavHealthInfoForSV();

      GetBeiDouCNavHealthInfoForSV(int svId);
  
      static GetBeiDouCNavHealthInfoForSVPtr create(int svId);
      static GetBeiDouCNavHealthInfoForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

