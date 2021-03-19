#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssUraIndex is deprecated since 21.3. You may use SetQzssUraIndexForSV.
    /// 
    /// Set the URA index of a QZSS satellite
    ///
    /// Name Type Description
    /// ---- ---- -------------------
    /// SvId int  The satellite SV ID
    /// Urai int  URA index.
    ///

    class SetQzssUraIndex;
    typedef std::shared_ptr<SetQzssUraIndex> SetQzssUraIndexPtr;
    
    
    class SetQzssUraIndex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssUraIndex();

      SetQzssUraIndex(int svId, int urai);
  
      static SetQzssUraIndexPtr create(int svId, int urai);
      static SetQzssUraIndexPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** urai ****
      int urai() const;
      void setUrai(int urai);
    };
  }
}

