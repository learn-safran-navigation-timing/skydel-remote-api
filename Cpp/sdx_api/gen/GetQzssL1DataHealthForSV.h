#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS L1 C/A nav data health
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssL1DataHealthForSV;
    typedef std::shared_ptr<GetQzssL1DataHealthForSV> GetQzssL1DataHealthForSVPtr;
    
    
    class GetQzssL1DataHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1DataHealthForSV();

      GetQzssL1DataHealthForSV(int svId);
  
      static GetQzssL1DataHealthForSVPtr create(int svId);
      static GetQzssL1DataHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

