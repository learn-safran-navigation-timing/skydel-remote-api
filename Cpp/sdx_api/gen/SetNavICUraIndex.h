#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetNavICUraIndex is deprecated since 21.3. You may use SetNavICUraIndexForSV.
    /// 
    /// Set the URA index of a NavIC satellite
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.
    /// Urai        int             URA index.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetNavICUraIndex;
    typedef std::shared_ptr<SetNavICUraIndex> SetNavICUraIndexPtr;
    
    
    class SetNavICUraIndex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetNavICUraIndex();

      SetNavICUraIndex(int svId, int urai, const std::optional<std::string>& dataSetName = {});

      static SetNavICUraIndexPtr create(int svId, int urai, const std::optional<std::string>& dataSetName = {});
      static SetNavICUraIndexPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** urai ****
      int urai() const;
      void setUrai(int urai);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

