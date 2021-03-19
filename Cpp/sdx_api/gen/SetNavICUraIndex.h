#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetNavICUraIndex is deprecated since 21.3. You may use SetNavICUraIndexForSV.
    /// 
    /// Set the URA index of a NavIC satellite
    ///
    /// Name Type Description
    /// ---- ---- -------------------
    /// SvId int  The satellite SV ID
    /// Urai int  URA index.
    ///

    class SetNavICUraIndex;
    typedef std::shared_ptr<SetNavICUraIndex> SetNavICUraIndexPtr;
    
    
    class SetNavICUraIndex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNavICUraIndex();

      SetNavICUraIndex(int svId, int urai);
  
      static SetNavICUraIndexPtr create(int svId, int urai);
      static SetNavICUraIndexPtr dynamicCast(CommandBasePtr ptr);
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

