#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set QZSS L1 C/A nav data health
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health int  Data health 0..7
    ///

    class SetQzssL1DataHealthForSV;
    typedef std::shared_ptr<SetQzssL1DataHealthForSV> SetQzssL1DataHealthForSVPtr;
    
    
    class SetQzssL1DataHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssL1DataHealthForSV();

      SetQzssL1DataHealthForSV(int svId, int health);
  
      static SetQzssL1DataHealthForSVPtr create(int svId, int health);
      static SetQzssL1DataHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

